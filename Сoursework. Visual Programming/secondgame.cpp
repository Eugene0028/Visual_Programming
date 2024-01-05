#include "secondgame.h"
#include "ui_secondgame.h"
SecondGame::SecondGame(QWidget *parent, QString name, QSqlTableModel* model) :
    QWidget(parent),
    ui(new Ui::SecondGame)
{
    ui->setupUi(this);

    settings = new QSettings("Logopedia", "SettingsLogopedia", this);
    setObjectName(name);
    setWindowTitle(name);

    tmp_model = model;
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    loadSettings();

}

void SecondGame::saveSettings()
{
    settings->beginGroup("forma");
    settings->beginGroup(objectName());
    settings->setValue("geometry", geometry());
    settings->endGroup();
    settings->endGroup();
}

void SecondGame::loadSettings()
{
    settings->beginGroup("forma");
    settings->beginGroup(objectName());
    setGeometry(settings->value("geometry", QRect(630, 200, 900, 700)).toRect());
    settings->endGroup();
    settings->endGroup();
}

void SecondGame::Start()
{
    QPixmap background;
    if (!background.load(QStringLiteral("C:\\Users\\Eugene\\Documents\\curswork\\src\\background\\2.png")))return;
    scene->addPixmap(background);
    StartAudio("C:/Users/Eugene/Documents/curswork/src/music/3.wav");
    InitArray(L);
    InitArray(R);
    InitSprites(R, "R");
    InitSprites(L, "L");

    RectR = scene->addRect(47,400,220,150);
    RectR->setData(1, "L");
    RectR->setOpacity(0);

    RectL = scene->addRect(520,380,220,160);
    RectL->setData(2, "R");
    RectL->setOpacity(0);
    timer = new QTimer(this);
    time = 0;
    GamePlay();
}



void SecondGame::GamePlay()
{
    if (status)
    {
        connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
        timer->start(1000);
    }
}




void SecondGame::Won()
{
    mPlayer->stop();
    StartAudio("C:/Users/Eugene/Documents/curswork/src/music/1.wav");
    QMessageBox::information(this, "Поздравляю!", "Вы успешно справились с заданием!");
    mPlayer->stop();
    on_pushButton_clicked();
}

void SecondGame::StartAudio(QString str)
{
    mPlayer = new QMediaPlayer(this);
    mPlaylist = new QMediaPlaylist(mPlayer);
    mPlayer->setPlaylist(mPlaylist);
    mPlaylist->addMedia(QUrl(str));
    mPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    mPlayer->play();
}




void SecondGame::InitArray(QGraphicsPixmapItem **arr)
{
    for (int i = 0; i < 5; ++i) {
        arr[i] = new QGraphicsPixmapItem();
    }
}
void SecondGame::InitSprites(QGraphicsPixmapItem** arr, QString str)
{
    QPixmap newItem;
    for (int i = 0; i < 5; i++) {
        QString tmp = "C:\\Users\\Eugene\\Documents\\curswork\\src\\" + str + "\\" + QString::number(i + 1) + ".png";
        newItem.load(tmp);
        arr[i] = scene->addPixmap(newItem);
        arr[i]->setFlag(QGraphicsItem::ItemIsMovable);
        if (str == "R")
        {
            i % 2 == 0 ? arr[i]->setPos(108 * (i + 1) , 150) : arr[i]->setPos(108 * (i + 1), 50);
            arr[i]->setData(0, "R");
        }
        if (str == "L")
        {
            i % 2 == 0 ? arr[i]->setPos(108 * (i + 1) , 50) : arr[i]->setPos(108 * (i + 1), 150);
            arr[i]->setData(0, "L");
        }
    }
}

SecondGame::~SecondGame()
{
    saveSettings();
    delete ui;
}

void SecondGame::on_pushButton_clicked()
{
    status = false;
    if (tmp_model == nullptr) return;
    QSqlTableModel* model = tmp_model;


        int rowCount = model->rowCount();
        bool flag  = false;
        QModelIndex timeIndex;
        for (int row = 0; row < rowCount; row++)
        {
            QModelIndex nameIndex = model->index(row, 0);
            QModelIndex lastNameIndex = model->index(row, 1);

            QString existingName = model->data(nameIndex).toString();
            QString existingLastName = model->data(lastNameIndex).toString();
            if (existingName == name && existingLastName == lastName && row == position)
            {
                flag = true;
                timeIndex = model->index(row, 2);
                break;
            }
        }
        if (flag)
        {
            model->setData(timeIndex, time-1);
        }
        else
        {
            model->insertRow(rowCount);
            QModelIndex index;

            index = model->index(rowCount, 0); // Имя column
            model->setData(index, name);

            index = model->index(rowCount, 1); // Фамилия column
            model->setData(index, lastName);

            index = model->index(rowCount, 2); // Время выполнения column
            model->setData(index, time-1);

            model->submitAll();
            model->select();
        }


    tmp_model = model;
    delete timer;
    delete mPlayer;
    this->close();
    emit back();
}

#include "iostream"
void SecondGame::Block(QGraphicsPixmapItem* item)
{
    int x = item->x(), y= item->y();
    if (x < 0) item->setPos(0, y);
    if (x > 650) item->setPos(650, y);
    if (y < 0) item->setPos(x, 0);
    if (y > 480) item->setPos(x,480);

}

bool SecondGame::observer_ward(int oldX, int oldY)
{
    return oldX <= 800 && oldX >= 0 && oldY <= 600 && oldY >= 0;
}

void SecondGame::onTimeout()
{

    ui->label->setText(QString::number(time++));
    int cntL = 0, cntR = 0;
    for (int i = 0; i < 5; i++)
    {
        L[i]->collidesWithItem(RectL) ? cntL++ : cntL--;
        R[i]->collidesWithItem(RectR) ? cntR++ : cntR--;
        Block(L[i]);
        Block(R[i]);
    }
    if (cntR + cntL == 10)
    {
        time = 0;
        Won();
    }

}
