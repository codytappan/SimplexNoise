#include "mainwindow.h"
#include "ResizeHandler.h"

#include "../image/bitmap.h"

#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    view(new QGraphicsView)
{
    this->setCentralWidget(view);

    view->setScene(new QGraphicsScene);

    // Install resize handler
    ResizeHandler *handler = new ResizeHandler(this);
    QCoreApplication::instance()->installEventFilter(handler);

    connect(handler, SIGNAL(resized(int, int)), this, SLOT(UpdateImage(int, int)));
}

MainWindow::~MainWindow()
{
    delete view;
}

void MainWindow::UpdateImage(int width, int height) {
    cout << "Updating image\n";
    cout << "Width: " << width << "\n";
    cout << "Height: " << height << "\n";

    cout << "Gen bitmap\n";
    Bitmap bitmap(width, height);

    cout << "Populate img\n";
    QImage img(bitmap.GetImageData()->data(), width, height, QImage::Format_Indexed8);

    cout << "Clear scene\n";
    view->scene()->clear();

    cout << "Add img\n";
    view->scene()->addPixmap(QPixmap::fromImage(img));

    cout << "Update view\n";
    view->update();
}

