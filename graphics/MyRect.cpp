#include "MyRect.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include "Ball.h"
#include <QGraphicsScene>
#include <QRandomGenerator>

int flag =0;

void MyRect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{


    qreal mouseX = event->scenePos().x();

    if (mouseX > 0 && mouseX < 700) {
        setPos(mouseX - rect().width() / 2, y());
    }


}

void MyRect::keyPressEvent(QKeyEvent *event1)
{
    if(flag==0){

    if(event1->key() == Qt::Key_Space)
    {
        Ball * ball = new Ball();
        ball->setPos(this->x() + (this->rect().width() / 2) - (ball->rect().width() / 2), this->y() - ball->rect().height() );

        // int angle = QRandomGenerator::global()->bounded(30, 151);

        // ball->setRotation(-1 * angle);
        scene()->addItem(ball);
    }
    flag =1;
    }

}

MyRect::MyRect()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    setAcceptedMouseButtons(Qt::NoButton);
}
