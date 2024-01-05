#ifndef CHOOSE_H
#define CHOOSE_H

#include <QWidget>
#include "firstgame.h"
#include "secondgame.h"
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
namespace Ui {
class choose;
}

class choose : public QWidget
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = 0, QString name = "MainForm", QSqlTableModel* model = nullptr);
    ~choose();
signals:
    void back();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    void saveSettings();
    void loadSettings();
    QSettings* settings;
    Ui::choose *ui;
    FirstGame *first_game;
    SecondGame* second_game;
    void InitMiniIcons();
};

#endif // CHOOSE_H
