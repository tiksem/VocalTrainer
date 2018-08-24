#include "qopenglworkspacewidget.h"
#include <QMouseEvent>

QOpenGLWorkspaceWidget::QOpenGLWorkspaceWidget(QWidget* parent) : QOpenGLWidget(parent)
{

}

void QOpenGLWorkspaceWidget::initializeGL() {
    setupWorkspaceDrawer(this);
}

void QOpenGLWorkspaceWidget::resizeGL(int w, int h) {
    handleResize(this, w, h);
}

void QOpenGLWorkspaceWidget::paintGL() {
    workspaceDrawer->draw();
}

void QOpenGLWorkspaceWidget::mousePressEvent(QMouseEvent *event) {

}

void QOpenGLWorkspaceWidget::mouseMoveEvent(QMouseEvent *event) {

}

QOpenGLWorkspaceWidget::~QOpenGLWorkspaceWidget() {

}
