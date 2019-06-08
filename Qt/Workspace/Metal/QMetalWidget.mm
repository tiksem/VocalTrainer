#include "QMetalWidget.h"
#include <QResizeEvent>
#include <QMacNativeWidget>
#include "Utils/QtUtils.h"
#include "Executors.h"

using namespace CppUtils;

#define LOCK std::lock_guard<std::mutex> _(sizeMutex)

QMetalWidget::QMetalWidget(QWidget *parent)
    : QMacCocoaViewContainer(nil, parent)
{
    // Post to the end of main thread queue to ensure QMetalWidget vtable is initialised
    Executors::ExecuteOnMainThread([=] {
        metalView = [[MetalView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)
                                            callback:this andDevicePixelRatio:devicePixelRatioF()];
        setCocoaView(metalView);
    }, true);
}

void QMetalWidget::resizeEvent(QResizeEvent *event) {
    [metalView resize:event->size().toCGSize()];
}

CAMetalLayer *QMetalWidget::getLayer() const {
    return metalView.metalLayer;
}

void QMetalWidget::addSubview(NSView* view) {
    NSView* parent = QtUtils::getNSView(this);
    [parent addSubview:view positioned:NSWindowAbove relativeTo:nil];
}

QMacNativeWidget*  QMetalWidget::addSubWidget(QWidget* widget) {
    auto *nativeWidget = new QMacNativeWidget();
//    widget->setParent(nativeWidget);
//    NSView *nativeWidgetView = QtUtils::getNSView(nativeWidget);
//    addSubview(nativeWidgetView);
//    nativeWidget->show();
//
//    nativeWidget->resize(widget->size());
//    QtUtils::AddResizeListener(widget, [&] (int width, int height) {
//        nativeWidget->resize(width, height);
//    }

    return nativeWidget;
}

void QMetalWidget::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
}
