#ifndef BRICKS_H
#define BRICKS_H
#include <QGraphicsRectItem>
#include <QColor>

class Bricks: public QGraphicsRectItem{
public:
    Bricks(const QColor& color);
};

#endif
