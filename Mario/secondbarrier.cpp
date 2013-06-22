#include "secondbarrier.h"

SecondBarrier::SecondBarrier()
{
    this->setPos(280, 570);
}

QRectF SecondBarrier::boundingRect() const
{
    QRectF rect(0, 0, myWidth, myHeight);
    return rect.adjusted(-2, -2, 2, 2);
}

void SecondBarrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(0, 0, myWidth, myHeight);
}
