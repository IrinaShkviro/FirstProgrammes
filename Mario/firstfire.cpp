#include "firstfire.h"

FirstFire::FirstFire()
{
    this->setPos(340, 595);
}
QRectF FirstFire::boundingRect() const
{
    QRectF rect(0, 0, myWidth, myHeight);
    return rect.adjusted(-2, -2, 2, 2);
}

void FirstFire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, myWidth, myHeight);
}
