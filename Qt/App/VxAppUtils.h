//
// Created by Semyon Tikhonenko on 2018-12-16.
//

#ifndef VOCALTRAINER_VXAPPUTILS_H
#define VOCALTRAINER_VXAPPUTILS_H


#include <QWidget>

namespace VxAppUtils {
    void OpenExistingProject(QWidget *parent, const std::function<void(bool)> &onFinish);
    void OpenProject(QWidget *parent, const QString &fileName, const std::function<void(bool)> &onFinish);
}


#endif //VOCALTRAINER_VXAPPUTILS_H
