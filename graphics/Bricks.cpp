#include "Bricks.h"
#include <QColor>
#include <QBrush>

Bricks::Bricks(const QColor& color)
{
    this->setBrush(QBrush(color));
}
