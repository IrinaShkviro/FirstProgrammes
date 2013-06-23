#include "mario.h"

Mario::Mario()
{
    this->setPos(2, sceneHeight - mySize - 2);
}

QRectF Mario::boundingRect() const
{
    QRectF rect(0, 0, mySize, mySize);
    return rect.adjusted(-2, -2, 2, 2);
}

void Mario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *GameWidget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, mySize, mySize);
}

void Mario::space()
{
    /*QTimer *deltaTimer = new QTimer();
    connect(deltaTimer, SIGNAL(timeout()), this, SLOT(jump()));
    QTimer *boardTimer = new QTimer();
    connect(boardTimer, SIGNAL(timeout()), this, SLOT(stopTimer(deltaTimer)));
    deltaTimer->start(75);
    boardTimer->start(500);*/
    for (int i = 0; i < 200; i++)
    {
        QTimer::singleShot(1000, this, SLOT(jump()));
    }
    for (int i = 0; i < 200; i++)
    {
        QTimer::singleShot(1000, this, SLOT(down()));
    }
}

void Mario::jump()
{
    this->moveBy(0, -1);
}
void Mario::down()
{
    this->moveBy(0, 1);
}
