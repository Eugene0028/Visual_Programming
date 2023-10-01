#include "flatmainwindow.h"
#include "ui_flatmainwindow.h"
#include <QGraphicsScene>
FlatMainWindow::FlatMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FlatMainWindow)
{
    ui->setupUi(this);
    GraphicsFlat* scene = new GraphicsFlat;
    ui->graphicsView->setScene(scene);
}

FlatMainWindow::~FlatMainWindow()
{
    delete ui;
}
