#include "choose.h"
#include "ui_choose.h"
#include <QInputDialog>
choose::choose(QWidget *parent, QString name, QSqlTableModel* model) :
    QWidget(parent),
    ui(new Ui::choose)
{
    ui->setupUi(this);
    QApplication::setOrganizationName("None");
    QApplication::setApplicationName("Logopedia");
    InitMiniIcons();
    first_game = new FirstGame(0, "FirstGame", model);
    second_game = new SecondGame(0, "SecondGame", model);

    settings = new QSettings("Logopedia", "SettingsLogopedia", this);
    setObjectName(name);
    setWindowTitle(name);


    connect(first_game, &FirstGame::back, this, FirstGame::show);
    connect(second_game, &SecondGame::back, this, SecondGame::show);
    loadSettings();
}

choose::~choose()
{
    saveSettings();
    delete ui;
}

void choose::saveSettings()
{
    settings->beginGroup("forma");
    settings->beginGroup(objectName());
    settings->setValue("geometry", geometry());
    settings->endGroup();
    settings->endGroup();
}

void choose::loadSettings()
{
    settings->beginGroup("forma");
    settings->beginGroup(objectName());
    setGeometry(settings->value("geometry", QRect(630, 200, 600, 410)).toRect());
    settings->endGroup();
    settings->endGroup();
}


void choose::on_pushButton_clicked()
{
    this->hide();
    //delete first_game;
    emit back();
}


void choose::on_pushButton_2_clicked()
{
    // Hide the current window
    this->hide();

    // Create an input dialog for the user to enter their name, last name, and position in the table
    QString name = QInputDialog::getText(this, "Enter Information", "Enter your Name:");
    QString lastName = QInputDialog::getText(this, "Enter Information", "Enter your Last Name:");
    int position = QInputDialog::getInt(this, "Enter Information", "Enter your Position in the Table:");

    // Update the information of the first_game object with the entered values
    first_game->name = name;
    first_game->lastName = lastName;
    first_game->position = position;

    // Set the status of first_game to true and start the game
    first_game->status = true;
    first_game->Start();
    first_game->time = 0;
    // Show the first_game window
    first_game->show();
}

void choose::on_pushButton_5_clicked()
{
    this->hide();
    // Create an input dialog for the user to enter their name, last name, and position in the table
    QString name = QInputDialog::getText(this, "Enter Information", "Enter your Name:");
    QString lastName = QInputDialog::getText(this, "Enter Information", "Enter your Last Name:");
    int position = QInputDialog::getInt(this, "Enter Information", "Enter your Position in the Table:");

    // Update the information of the first_game object with the entered values
    second_game->name = name;
    second_game->lastName = lastName;
    second_game->position = position;

    second_game->status = true;
    second_game->Start();
    second_game->show();
}

void choose::InitMiniIcons()
{
    QPixmap image[4];
    for (int i = 0; i < 4; i++)
    {
        image[i].load("C:\\Users\\Eugene\\Documents\\curswork\\src\\miniBack\\" + QString::number(i + 1) + ".png");
    }
    //ui->label->setPixmap(image[0]);
    ui->label_4->setPixmap(image[1]);
    ui->label_3->setPixmap(image[2]);
    //ui->label_2->setPixmap(image[3]);
}
