#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include "form.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("C:\\Users\\Eugene\\Documents\\curswork\\style.css");
    file.open(QFile::ReadOnly);
    a.setStyleSheet(file.readAll());

    QApplication::setOrganizationName("None");
    QApplication::setApplicationName("Logopedia");
    MainWindow w(0, "StartDialog");
    w.show();

    return a.exec();
}
