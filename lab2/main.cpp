#include "mainwindow.h"
#include <QApplication>
#include "startdialog_eugene_flat.h".h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_Eugene_Flat startDialog;
    startDialog.resize(400, 300);
    startDialog.setText("Нажми Сюда!");
    startDialog.show();

    return a.exec();
}
