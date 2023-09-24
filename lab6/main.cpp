#include "mainwindow.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("C:\\Users\\Eugene\\Desktop\\Visual_Programming\\lab6\\style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());
    MainWindow w;
    w.show();
    return a.exec();
}
