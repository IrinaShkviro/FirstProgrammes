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
    QTimer *deltaTimer = new QTimer();
    QObject::connect(deltaTimer, SIGNAL(timeout()), this, SLOT(jump()));
    deltaTimer->start(75);
}

void Mario::jump()
{
    this->moveBy(0, 5);
}
