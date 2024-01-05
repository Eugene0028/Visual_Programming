#include "form.h"
#include "ui_form.h"
#include "customdelegate.h"
#include <QMessageBox>
Form::Form(QWidget *parent, QString name) :
    QWidget(parent),
    ui(new Ui::Form)
{
    QApplication::setOrganizationName("None");
    QApplication::setApplicationName("Logopedia");
    ui->setupUi(this);


    settings = new QSettings("Logopedia", "SettingsLogopedia", this);
    setObjectName(name);
    setWindowTitle(name);


    DataBase = QSqlDatabase::addDatabase("QSQLITE");
    DataBase.setDatabaseName("C:\\Users\\Eugene\\Documents\\curswork\\src\\database\\DB.db");
    if (DataBase.open()){ui->label_3->setText("Вы успешно подключились к базе данных" + DataBase.databaseName());InitBase();}
    else ui->label_3->setText("При подключении к базе данных произошла ошибка: " + DataBase.lastError().text());
    loadSettings();
    a = new choose(0, "Choose game", model);
    connect(a, &choose::back, this, choose::show);
}




Form::~Form()
{
    saveSettings();
    delete ui;
}

void Form::saveSettings()
{
    settings->beginGroup("forma");
    settings->beginGroup(objectName());
    settings->setValue("geometry", geometry());
    settings->endGroup();
    settings->endGroup();
}

void Form::loadSettings()
{
    settings->beginGroup("forma");
    settings->beginGroup(objectName());
    setGeometry(settings->value("geometry", QRect(630, 200, 750, 510)).toRect());
    settings->endGroup();
    settings->endGroup();
}


void Form::on_pushButton_clicked()
{
    this->hide();
    emit firstWindow();
}

void Form::on_pushButton_2_clicked()
{
    this->hide();
    a->show();
}


void Form::InitBase()
{
    model = new QSqlTableModel(this, DataBase);
    model->setTable("Ученики");
    model->select();
    ui->tableView->setModel(model);

    CustomDelegate *delegate = new CustomDelegate(ui->tableView);
    ui->tableView->setItemDelegateForColumn(0, delegate); // Имя
    ui->tableView->setItemDelegateForColumn(1, delegate); // Фамилия
}

void Form::on_pushButton_3_clicked()
{
    model->insertRow(model->rowCount());
}

void Form::on_pushButton_4_clicked()
{
    model->removeRow(currentRow);
    model->select();
}


void Form::on_tableView_clicked(const QModelIndex &index)
{
    currentRow = index.row();
}




