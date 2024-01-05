 #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString name) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = new Form(0, "Form");
    settings = new QSettings("Logopedia", "SettingsLogopedia", this);
    setObjectName(name);
    setWindowTitle(name);

    connect(a, &Form::firstWindow, this, MainWindow::show);
    loadSettings();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    a->show();
}



void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::saveSettings()
{
    settings->beginGroup("forma");
    settings->beginGroup(objectName());
    settings->setValue("geometry", geometry());
    settings->endGroup();
    settings->endGroup();
}

void MainWindow::loadSettings()
{
    settings->beginGroup("forma");
    settings->beginGroup(objectName());
    setGeometry(settings->value("geometry", QRect(200, 200, 300, 300)).toRect());
    settings->endGroup();
    settings->endGroup();
}
