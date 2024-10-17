#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QPen>
#include <QColor>
#include <QObject>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include <QSoundEffect>

class Ball:public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
public:
    Ball();
public slots:
    void move();
    void checkPaleteCollision(QGraphicsRectItem * palete);



private:
    double dx;
    double dy;

};



#endif
