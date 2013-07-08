#include "fire.h"

Fire::Fire( int width, int height, int posX, int posY):
    myWidth(width),
    myHeight(height)
{
    this->setPos(posX, posY);
    myFireBrush.setTextureImage(QImage(":/Fire.jpg"));
}
QRectF Fire::boundingRect() const
{
    QRectF rect(0, 0, myWidth, myHeight);
    return rect.adjusted(-2, -2, 2, 2);
}

void Fire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(myFireBrush);
    painter->drawRect(0, 0, myWidth, myHeight);
}
