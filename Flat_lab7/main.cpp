#include "flatmainwindow.h"
#include <QApplication>
#include<QHBoxLayout>
#include<QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlatMainWindow w;
    w.setFixedSize(800,500);
    w.show();

    return a.exec();
}

