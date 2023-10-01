#include "graphicsflat.h"
#include<iostream>

#include<QHBoxLayout>
#include<QLabel>




void GraphicsFlat::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Up){
        speed < 4 ? speed++ : speed;
    }
    if(event->key() == Qt::Key_Down){
        speed = qMax(speed - 1, 1);
    }
 }

void GraphicsFlat::MoveKnight(){
    if(!collidingItems(knight).isEmpty())
    {
        int tmp1 = qrand() % 3 - 1;
        int tmp2 = qrand() % 3 - 1;
        dx != tmp1 ? dx=tmp1 : dx*=-1;
        dy != tmp2 ? dy = tmp2 : dy *=-1;
    }

       knight->setTransform(knight->transform().translate(dx * speed, dy * speed));




//       QPolygon poligoneTube;
//       poligoneTube << QPoint(0, 0) << QPoint(40, 0)<<QPoint(40, 60)<<QPoint(0, 60);
//       QGraphicsPolygonItem* tube = addPolygon(poligoneTube, QPen(Qt::black), QBrush(QColor(127, 127, 127)));
//       tube->setPos(300, 400);
//       tube->setFlags(QGraphicsItem::ItemIsMovable);

//       QGraphicsTextItem* textItem = new QGraphicsTextItem(QString::number(knight->x()), tube);
//       textItem->setDefaultTextColor(Qt::white);
//       textItem->setPos(10, 10); // set the position of the text on the figure
}


GraphicsFlat::GraphicsFlat(QObject* parent):QGraphicsScene (parent)
{

    int StartY = 450;

    for (int j = 0; j < 7; j++, StartY -= 60)
    {
        int StartX = 90;
        for (int i = 0; i < 7; i++, StartX+=40)
        {

            QPolygon poligoneTube;
            poligoneTube << QPoint(0, 0) << QPoint(40, 0)<<QPoint(40, 60)<<QPoint(0, 60);
            QGraphicsPolygonItem* tube = addPolygon(poligoneTube, QPen(Qt::black), QBrush(QColor(127, 127, 127)));
            if ((i == 1 || i == 2 || i == 4 || i == 5) && j == 6)tube->setBrush(QBrush(QColor(255, 255, 255)));
            tube->setPos(StartX, StartY);
            tube->setFlags(QGraphicsItem::ItemIsMovable);
        }
    }



    QPixmap newImage;
    if (!newImage.load(QStringLiteral("C:\\Users\\Eugene\\Documents\\Flat_lab7\\images\\torch.png")))return;
    QGraphicsPixmapItem* window[3];
    for(int i=0; i<3; i++)
    {
            window[i] = addPixmap(newImage);
            window[i]->setScale(0.15);
            window[i]->setData(0, "Tower");
            window[i]->setFlags(QGraphicsItem::ItemIsMovable);
    }
    window[0]->setPos(93,13);
    window[1]->setPos(213,13);
    window[2]->setPos(333,13);


    if (!newImage.load(QStringLiteral("C:\\Users\\Eugene\\Documents\\Flat_lab7\\images\\knight.png")))return;
    knight =addPixmap(newImage);
    knight->setScale(0.15);
    knight->setPos(600, 300);
    knight->setFlags(QGraphicsItem::ItemIsMovable);

    walls[0] = addRect(QRectF(0,0,10,500),QPen(Qt::black), QBrush(QColor(63, 72, 204)));
    walls[1] = addRect(QRectF(800,0,10,500), QPen(Qt::black), QBrush(QColor(63, 72, 204)));
    walls[2] = addRect(QRectF(0,0,800,10), QPen(Qt::black), QBrush(QColor(63, 72, 204)));
    walls[3] = addRect(QRectF(0,500,800,10), QPen(Qt::black), QBrush(QColor(63, 72, 204)));


    dx = 1;
    dy = 1;
    speed = 1;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MoveKnight()));
    timer->start(10);


}



