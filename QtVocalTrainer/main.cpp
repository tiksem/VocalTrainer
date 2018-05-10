#include <QGuiApplication>
#include <QQuickView>
#include "MainWindow.h"
#include "QmlCppBridge.h"
#include <QScreen>
#include <QQmlContext>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    MainWindow viewer;

    QQmlContext* context = viewer.rootContext();
    context->setContextProperty("cpp", new QmlCppBridge(&viewer));
    viewer.setSource(QUrl("qrc:/main.qml"));

    viewer.showMaximized();

    QSize size = viewer.size();
    std::cout<<size.height();
    
    return app.exec();
}