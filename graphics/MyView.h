#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "MyRect.h"

class MyView : public QGraphicsView {
    Q_OBJECT
public:
    MyView(QGraphicsScene* scene, MyRect* palete);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    MyRect* palete;
};

#endif
