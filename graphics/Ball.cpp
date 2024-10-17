#include "Ball.h"
#include <QTimer>
#include <QColor>
#include <qmath.h>
#include <QGraphicsScene>
#include "Bricks.h"
#include "MyRect.h"
#include <qmath.h>
#include <QtGlobal>
#include <QMediaPlayer>
#include <QDebug>
#include <QSoundEffect>


int flag1 =0;

Ball::Ball()
{
    setRect(0,0,20,20);

    QColor purpleColor = QColor(250, 0, 250);
    QGraphicsEllipseItem::setBrush(QBrush(purpleColor));
    setPen(QPen(Qt::black));

    dx = 8.66;
    dy = -5;


    QTimer * time = new QTimer();
    connect(time,SIGNAL(timeout()),this,SLOT(move()));


    time->start(50);


}

void Ball::move()
{


    // if(flag1 ==0){
    // int step_size = 10;
    // double theta = rotation();

    // dx = step_size * qCos(qDegreesToRadians(theta));
    // dy = step_size * qSin(qDegreesToRadians(theta));
    // setPos(x() +dx, y()+ dy);

    // }

    setPos(x() +dx, y()+ dy);

    if(pos().x()<=0 || pos().x() + rect().width() >=800)
    {
        dx = -dx;
    }
    if (this->pos().y()<=0)
    {
        dy = -dy;
    }

    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    for (QGraphicsItem *item : collidingItems) {
        if (typeid(*item) != typeid(Bricks)) {
            checkPaleteCollision(qgraphicsitem_cast<QGraphicsRectItem *>(item));
            break;
        }
    }

    if (pos().y() >= 600) {
        setPos(400, 300);
        dx = 8.66;
        dy = -5;
    }

    for(int i = 0; i<collidingItems.size(); i++)
    {
        if(typeid(*collidingItems[i])==typeid(Bricks))
        {
            if((collidingItems[i]->x()== (this->x() + rect().width()/2)) && ((collidingItems[i]->x() + collidingItems[i]->boundingRect().width())==(this->x()  - rect().width()/2)))
            {
                dx = -dx;
            }
            else
            {
                dy = -dy;
            }
            scene()->removeItem(collidingItems[i]);
            delete collidingItems[i];

    }

    }
}

void Ball::checkPaleteCollision(QGraphicsRectItem *paddle)
{
    if (collidesWithItem(paddle)) {
            qreal paddleCenter = paddle->x() + paddle->rect().width() / 2;
            qreal ballCenter = x() + rect().width() / 2;

            qreal difference = ballCenter - paddleCenter;
            qreal normalizedDifference = qAbs(difference / (paddle->rect().width() / 2));

            qreal speed = qSqrt(dx * dx + dy * dy);

            qreal angle = normalizedDifference * (45.0);

            qreal angleInRadians = qDegreesToRadians(angle);

            dx = speed * qCos(angleInRadians);
            dy = -speed * qSin(angleInRadians);
        }
}





