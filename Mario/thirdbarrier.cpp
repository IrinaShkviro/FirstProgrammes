#include "thirdbarrier.h"

ThirdBarrier::ThirdBarrier()
{
    this->setPos(400, 550);
}
QRectF ThirdBarrier::boundingRect() const
{
    QRectF rect(0, 0, myWidth, myHeight);
    return rect.adjusted(-2, -2, 2, 2);
}
void ThirdBarrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(0, 0, myWidth, myHeight);
}

