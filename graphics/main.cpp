#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Ball.h"
#include "MyRect.h"
#include "MyView.h"
#include <QBrush>
#include <QColor>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <QTimer>
#include "Bricks.h"

void createBricks(QGraphicsScene* scene, int offset, const QColor& color) {
    int brickWidth = 30;
    int brickHeight = 15;
    int spacing = 5;

    int rows =1;
    int columns = (800+spacing)/(brickWidth+spacing);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            Bricks* brick = new Bricks(color);

            int xPos = j * (brickWidth + spacing);
            int yPos = i * (brickHeight + spacing) + offset;

            brick->setRect(0, 0, brickWidth, brickHeight);
            brick->setPos(xPos, yPos);



            scene->addItem(brick);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();

    scene->setBackgroundBrush(QBrush(Qt::black));


    QColor platecolor = QColor(128, 128, 128);


    MyRect * palete = new MyRect();
    palete->setRect(0,0,100,10);
    palete->setBrush(QBrush(platecolor));

    scene->addItem(palete);




    MyView *view = new MyView(scene, palete);
    view->setScene(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    palete->setPos(view->width()/2 - palete->rect().width()/2, view->height()-palete->rect().height() -50);

    QColor redbrickColor = QColor(255, 0, 0);
    QColor orangebrickColor = QColor(255, 165, 0);
    QColor yellowbrickColor = QColor(255, 255, 0);
    QColor greenbrickColor = QColor(0, 255, 0);
    QColor bluebrickColor = QColor(0, 0, 255);


    createBricks(scene,50,redbrickColor);
    createBricks(scene,70,orangebrickColor);
    createBricks(scene,90,yellowbrickColor);
    createBricks(scene,110,greenbrickColor);
    createBricks(scene,130,bluebrickColor);

    view->show();


    return a.exec();
}
