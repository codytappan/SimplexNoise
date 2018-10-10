#ifndef RESIZER_H
#define RESIZER_H

#include <QTimer>
#include <QEvent>
#include <QMouseEvent>

static const int RESIZE_TIMEOUT = 500; // 1/2 second in milliseconds

namespace Ui {
class ResizeHandler;
typedef void (*ResizeDoneCallback)(unsigned int width, unsigned int height);
}

class ResizeHandler : public QObject
{
    Q_OBJECT

public:
    explicit ResizeHandler(QObject *parent = nullptr) : QObject(parent) {
        mResizeTimer = new QTimer(this);
        connect(mResizeTimer, SIGNAL(timeout()), this, SLOT(resizeTimeout()));
    };

    ~ResizeHandler() {};

public slots:
    void resizeTimeout();

signals:
    void resized(int newWidth, int newHeight);

protected:
    bool mUserResizing = false;
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    QTimer* mResizeTimer;

    int width;
    int height;

    void ResizeComplete();
};

#endif