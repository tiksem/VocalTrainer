#include "qtutils.h"
#include <QTimer>

namespace QtUtils {
    void startRepeatedTimer(QObject *parent, const std::function<bool()> &action, int intervalInMilliseconds) {
        assert(action);
        assert(intervalInMilliseconds >= 0);
        QTimer* timer = new QTimer(parent);
        timer->setInterval(intervalInMilliseconds);
        QObject::connect(timer, &QTimer::timeout, [=] {
            if (!action()) {
                timer->stop();
            }
        });
        timer->start(intervalInMilliseconds);
    }

    QFrame* createVerticalLine(int width, QWidget* parent) {
        QFrame* frame = new QFrame(parent);
        frame->setFrameShape(QFrame::VLine);
        frame->setLineWidth(width);
        frame->setFixedWidth(width);
        return frame;
    }
}