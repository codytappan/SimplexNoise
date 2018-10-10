#ifndef BITMAPPER_H
#define BITMAPPER_H

#include <QCoreApplication>
#include <QMainWindow>
#include <QGraphicsView>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void UpdateImage(int width, int height);

private:
    QGraphicsView *view;

    bool mUserResizing = false;
};

#endif // BITMAPPER_H
