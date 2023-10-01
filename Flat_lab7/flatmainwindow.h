#ifndef FLATMAINWINDOW_H
#define FLATMAINWINDOW_H

#include <QMainWindow>
#include "graphicsflat.h"
namespace Ui {
class FlatMainWindow;
}

class FlatMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FlatMainWindow(QWidget *parent = 0);
    ~FlatMainWindow();

private:
    Ui::FlatMainWindow *ui;
};

#endif // FLATMAINWINDOW_H
