﻿#ifndef QOPENGLWORKSPACEWIDGET_H
#define QOPENGLWORKSPACEWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLPaintDevice>
#include "WorkspaceDrawer.h"
#include "WorkspaceDrawerWidgetSetup.h"

class QOpenGLWorkspaceWidget : public QOpenGLWidget, WorkspaceDrawerWidgetSetup
{
    Q_OBJECT
public:
    QOpenGLWorkspaceWidget(QWidget* parent);
    ~QOpenGLWorkspaceWidget();
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
#ifdef USE_QT_DRAWER
    QOpenGLPaintDevice* device = nullptr;
#endif

    DrawerImpl* drawer;

    void initDeviceIfNeed();
};

#endif // QOPENGLWORKSPACEWIDGET_H