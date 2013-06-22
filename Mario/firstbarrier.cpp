#include "firstbarrier.h"

FirstBarrier::FirstBarrier()
{
    this->setPos(100, 550);
}

QRectF FirstBarrier::boundingRect() const
{
    QRectF rect(0, 0, myWidth, myHeight);
    return rect.adjusted(-2, -2, 2, 2);
}

void FirstBarrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(0, 0, myWidth, myHeight);
}
