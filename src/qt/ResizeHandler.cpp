#include "ResizeHandler.h"

bool ResizeHandler::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::Resize) {
        QResizeEvent *mLastEvent = dynamic_cast<QResizeEvent*>(event);

        width = mLastEvent->size().width();
        height = mLastEvent->size().height();

        if (!mUserResizing) {
            printf("Resize detected\n");
            mUserResizing = true;
        }

        mResizeTimer->start(RESIZE_TIMEOUT);
    }

    // We need to check for both types of mouse release, because it can vary on which type happens when resizing.
    else if ((event->type() == QEvent::MouseButtonRelease) || (event->type() == QEvent::NonClientAreaMouseButtonRelease)) {
        QMouseEvent* pMouseEvent = dynamic_cast<QMouseEvent*>(event);
        if (mUserResizing) {
            ResizeComplete();
        }
    }

    return QObject::eventFilter(obj, event); // pass it on without eating it
}

void ResizeHandler::ResizeComplete() {
    mUserResizing = false;

    printf("Resize done\n");
    mResizeTimer->stop();

    emit resized(width, height);
}

void ResizeHandler::resizeTimeout() {
    ResizeComplete();
}


