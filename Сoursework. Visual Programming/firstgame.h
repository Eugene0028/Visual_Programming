#ifndef FIRSTGAME_H
#define FIRSTGAME_H

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
class FirstGame;
}

class FirstGame : public QWidget
{
    Q_OBJECT

public:
    explicit FirstGame(QWidget *parent = 0, QString name = "MainForm", QSqlTableModel* model = nullptr);
    ~FirstGame();
    void Start();
    bool status;
    int time;
    QString name;
    QString lastName;
    int position;

signals:
    back();

private slots:
    void on_pushButton_clicked();
    void onTimeout();
private:
    void saveSettings();
    void loadSettings();
    QSettings* settings;
    QGraphicsPixmapItem** snake = new QGraphicsPixmapItem*[5];
    QGraphicsPixmapItem** bug = new QGraphicsPixmapItem*[5];
    QGraphicsRectItem* RectBug = new QGraphicsRectItem;
    QGraphicsRectItem* RectSnake = new QGraphicsRectItem;
    QMediaPlayer* mPlayer;
    QMediaPlaylist* mPlaylist;
    QGraphicsPixmapItem* background;
    Ui::FirstGame *ui;
    QGraphicsScene *scene;
    QTimer* timer;
    //Form* form;
    QSqlTableModel* tmp_model;

    void InitSprites(QGraphicsPixmapItem** arr, QString str);
    void InitArray(QGraphicsPixmapItem** arr);
    void GamePlay();
    void Won();
    void StartAudio(QString str);
    void Block(QGraphicsPixmapItem* item);
    bool observer_ward(int oldX, int oldY);
    void mouseMoveEvent(QGraphicsSceneEvent* event);
};

#endif // FIRSTGAME_H
