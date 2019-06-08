#ifndef QMetalWidget_H
#define QMetalWidget_H

#include <QWidget>
#include <mutex>
#import <QMacNativeWidget>
#import <QMacCocoaViewContainer>
#include "MetalViewCallback.h"
#ifdef __OBJC__
#import "MetalView.h"
#endif

class QMetalWidget : public QMacCocoaViewContainer, protected MetalViewCallback
{
public:
    explicit QMetalWidget(QWidget *parent = nullptr);
    QMacNativeWidget* addSubWidget(QWidget* widget);
protected:
#ifdef __OBJC__
    void addSubview(NSView* view);
    CAMetalLayer *getLayer() const;

    void showEvent(QShowEvent *event) override;

#endif
    void resizeEvent(QResizeEvent *event) override;
private:
#ifdef __OBJC__
    MetalView* metalView;
#else
    void* metalView;
#endif
};

#endif // QMetalWidget
