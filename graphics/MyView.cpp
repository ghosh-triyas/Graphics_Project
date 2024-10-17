#include "MyView.h"
#include <QMouseEvent>
#include "MyRect.h"

MyView::MyView(QGraphicsScene* scene, MyRect* palete)
    : QGraphicsView(scene), palete(palete) {
    setMouseTracking(true);  // Enable mouse tracking for the view
}

void MyView::mouseMoveEvent(QMouseEvent *event) {
    int mouseX = event->pos().x();

    if (mouseX > 50 && mouseX < this->width()-50) {
        palete->setPos(mouseX - palete->rect().width() / 2, palete->y());
    }
}
