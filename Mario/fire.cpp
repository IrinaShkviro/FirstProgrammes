#include "fire.h"

Fire::Fire(int posX, int posY, int width, int height):
    myWidth(width),
    myHeight(height)
{
    this->setPos(posX, posY);
}
QRectF Fire::boundingRect() const
{
    QRectF rect(0, 0, myWidth, myHeight);
    return rect.adjusted(-2, -2, 2, 2);
}

void Fire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, myWidth, myHeight);
}
