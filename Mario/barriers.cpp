#include "barriers.h"

Barriers::Barriers(int width, int height, int posX, int posY):
    myWidth(width),
    myHeight(height)
{
    this->setPos(posX, posY);
    myBarrierBrush.setTextureImage(QImage(":/Barriers.jpg"));
}

QRectF Barriers::boundingRect() const
{
    QRectF rect(0, 0, myWidth, myHeight);
    return rect.adjusted(-2, -2, 2, 2);
}

void Barriers::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(myBarrierBrush);
    painter->drawRect(0, 0, myWidth, myHeight);
}
