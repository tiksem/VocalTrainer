//
// Created by Semyon Tikhonenko on 2018-12-16.
//

#include "VxAppUtils.h"
#include "VxApp.h"
#include "AppSettings.h"
#include <QString>
#include <QFileDialog>
#include <QProgressDialog>

constexpr int DIALOG_MAXIMUM = 100;

namespace VxAppUtils {
    void OpenExistingProject(QWidget *parent, const std::function<void(bool)> &onFinish) {
        QString fileName = QFileDialog::getOpenFileName(
                parent, "Select .mvx file for signing", "", "Mvx files(*.mvx *.rvx);; All files(*)");

        bool fileSelected = !fileName.isEmpty();
        if (fileSelected) {
            OpenProject(parent, fileName, onFinish);
        } else {
            onFinish(false);
        }
    }

    void OpenProject(QWidget *parent, const QString &fileName, const std::function<void(bool)> &onFinish) {
        QProgressDialog* progressDialog = new QProgressDialog(parent);
        auto finished = [=] (bool success) {
            delete progressDialog;

            if (success) {
                AppSettings settings;
                if (MainController::instance()->getPlayer()->isRecording()) {
                    settings.addRecording(fileName);
                } else {
                    settings.addProject(fileName);
                }
            }

            onFinish(success);
        };

        bool decodingNeeded;
        OperationCancelerPtr operationCanceler;
        MainController::instance()->decodeAndSetAsPlayerSource(
                fileName.toLocal8Bit().data(), &decodingNeeded,
                [=] (float progress) { // progress listener
                    progressDialog->setValue(qRound(DIALOG_MAXIMUM * progress));
                }, [=] { // on task finished
                    finished(!operationCanceler->isCancelled());
                });
        if (!decodingNeeded) {
            finished(true);
        } else {
            progressDialog->setMaximum(DIALOG_MAXIMUM);
            progressDialog->setMinimum(0);
            progressDialog->setValue(0);
            QObject::connect(progressDialog, &QProgressDialog::canceled, [=] {
                operationCanceler->cancel();
            });
            progressDialog->show();
        }
    }
}