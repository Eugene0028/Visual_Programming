#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSettings>
#include "choose.h"
#include <QRegularExpressionValidator>
#include <QStyledItemDelegate>
#include <QItemDelegate>
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0, QString name = "MainForm");
    QSqlDatabase DataBase;
    QSqlTableModel* model;
    ~Form();


signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    void saveSettings();
    void loadSettings();
    QSettings* settings;
    Ui::Form *ui;
    choose *a;

    void InitBase();
    int currentRow;
};

#endif // FORM_H
