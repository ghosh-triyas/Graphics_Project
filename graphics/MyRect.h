#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsEllipseItem>
#include "Ball.h"
class MyRect: public QGraphicsRectItem{
public:
    MyRect();
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event1);
};

#endif
