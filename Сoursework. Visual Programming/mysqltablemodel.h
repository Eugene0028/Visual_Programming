#ifndef MYSQLTABLEMODEL_H
#define MYSQLTABLEMODEL_H
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

class MySqlTableModel : public QSqlTableModel
{
    QSqlTableModel* model;
    QSqlTableModel* get(){
        return model;
    }





};

#endif // MYSQLTABLEMODEL_H
