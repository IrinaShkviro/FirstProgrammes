#include "mario.h"

Mario::Mario()
{
    this->setPos(10, 10);
}

QRectF Mario::boundingRect() const
{
    qreal penWidth = 1;
    return (0 - penWidth/2, 0 - penWidth/2, 10 + penWidth/2, 10 + penWidth/2);
}

void Mario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *GameWidget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, 10, 10);
}
