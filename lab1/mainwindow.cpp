#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auth.h"
#include "ui_auth.h"
#include "QFileDialog.h"
#include "QTextDocumentWriter"
#include "QCloseEvent"
#include "QMessageBox"
void MainWindow::About_Lab1()
{
    Auth *dg  = new Auth();
    dg->show();
}

void MainWindow::slotOpen()
{
    QString filename = QFileDialog::getOpenFileName(0, "Открыть файл", QDir::currentPath(), "*.txt *.cpp *.c *.java *.py");
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->textEdit->setPlainText(file.readAll());
        file.close();
    }
}

void MainWindow::slotSave()
{
        QTextDocumentWriter writer;
        writer.setFileName(QFileDialog::getSaveFileName(0, "Сохранить файл", QDir::currentPath(), "*.txt *.cpp *.c *.java *.py"));
        writer.write(ui->textEdit->document());
}


void MainWindow::slotClear()
{
    ui->textEdit->clear();
}

void MainWindow::settings_for_OpenSlot(QMenu* pmnuFile){
    QAction* pactOpen = new QAction("file open action", 0);
    pactOpen->setText("Открыть");
    pactOpen->setShortcut(QKeySequence("CTRL+O"));
    pactOpen->setToolTip("Открытие документа");
    pactOpen->setStatusTip("Открыть файл");
    pactOpen->setWhatsThis("Oткрыть файл");
    pactOpen->setIcon(QPixmap("1.png"));

    connect(pactOpen, SIGNAL(triggered()), SLOT(slotOpen()));

    pmnuFile->addAction(pactOpen);
    menuBar()->addMenu(pmnuFile);
}

void MainWindow::settings_for_SaveSlot(QMenu* pmnuFile){
    QAction* pactSave = new QAction("file save action", 0);
    pactSave->setText("Сохранить");
    pactSave->setShortcut(QKeySequence("CTRL+S"));
    pactSave->setToolTip("Сохранение документа");
    pactSave->setStatusTip("Сохранить файл");
    pactSave->setWhatsThis("Сохранить файл");
    pactSave->setIcon(QPixmap("1.png"));
    connect(pactSave, SIGNAL(triggered()), SLOT(slotSave()));

    pmnuFile->addAction(pactSave);
    menuBar()->addMenu(pmnuFile);
}


void MainWindow::settings_for_ClearSlot(QMenu* pmnuFile)
{
    QAction* pactClear = new QAction("file clear action", 0);
    pactClear->setText("Очистить");
    pactClear->setShortcut(QKeySequence("CTRL+Q"));
    connect(pactClear, SIGNAL(triggered()), SLOT(slotClear()));
    pmnuFile->addAction(pactClear);
    menuBar()->addMenu(pmnuFile);
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Подтверждение закрытия", "Вы действительно хотите закрыть приложение?", QMessageBox::Yes | QMessageBox::No);
    reply == QMessageBox::Yes ?  QMainWindow::closeEvent(event) : event->ignore();
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->action_2, SIGNAL(triggered(bool)), this, SLOT(About_Lab1()));
    QMenu* pmnuFile = new QMenu("Файл");
    settings_for_OpenSlot(pmnuFile);
    settings_for_SaveSlot(pmnuFile);
    settings_for_ClearSlot(pmnuFile);

}

MainWindow::~MainWindow()
{
    delete ui;
}
