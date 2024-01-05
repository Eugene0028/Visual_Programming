 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include <QSettings>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString name = "MainForm");
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void saveSettings();
    void loadSettings();
    Ui::MainWindow *ui;
    Form *a;
    QSettings* settings;
};

#endif // MAINWINDOW_H
