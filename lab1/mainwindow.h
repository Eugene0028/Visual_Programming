#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //QMenu* pmnuFile=new QMenu("Файл");
    explicit MainWindow(QWidget *parent = 0);
    void settings_for_OpenSlot(QMenu* pmnuFile);
    void settings_for_SaveSlot(QMenu* pmnuFile);
    void settings_for_ClearSlot(QMenu* pmnuFile);
    void closeEvent(QCloseEvent *event);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void slotOpen();
    void slotSave();
    void slotClear();
    void About_Lab1();
};

#endif // MAINWINDOW_H
