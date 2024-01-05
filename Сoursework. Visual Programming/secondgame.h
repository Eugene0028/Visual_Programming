#ifndef SECONDGAME_H
#define SECONDGAME_H

#include <QWidget>
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>
#include <vector>
#include <QGraphicsRectItem>
#include <iostream>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
namespace Ui {
class SecondGame;
}

class SecondGame : public QWidget
{
    Q_OBJECT

public:
    explicit SecondGame(QWidget *parent = 0, QString name = "MainForm", QSqlTableModel* model = nullptr);
    ~SecondGame();
    void Start();
    bool status;
    int time;
    QString name;
    QString lastName;
    int position;

signals:
    back();

public slots:
    void on_pushButton_clicked();
    void onTimeout();
private:
    QGraphicsPixmapItem** L = new QGraphicsPixmapItem*[5];
    QGraphicsPixmapItem** R = new QGraphicsPixmapItem*[5];
    QGraphicsRectItem* RectL = new QGraphicsRectItem;
    QGraphicsRectItem* RectR = new QGraphicsRectItem;
    QMediaPlayer* mPlayer;
    QMediaPlaylist* mPlaylist;
    QGraphicsPixmapItem* background;
    Ui::SecondGame *ui;
    QGraphicsScene *scene;
    QTimer* timer;
    QSettings* settings;
    QSqlTableModel* tmp_model;
    void InitSprites(QGraphicsPixmapItem** arr, QString str);
    void InitArray(QGraphicsPixmapItem** arr);
    void GamePlay();
    void Won();
    void StartAudio(QString str);
    void Block(QGraphicsPixmapItem* item);
    bool observer_ward(int oldX, int oldY);
    void mouseMoveEvent(QGraphicsSceneEvent* event);
    void saveSettings();
    void loadSettings();
};

#endif // SECONDGAME_H
