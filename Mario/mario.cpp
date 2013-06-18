#include "mario.h"

Mario::Mario(int x, int y):
    myX(x),
    myY(y)
{
    this->setPos(myX, myY);
    this->setPos(myX + 300, myY + 200);
    this->ItemIsFocusable = 0x4;
    this->setFocus();
}

QRectF Mario::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2, 0 - penWidth/2, 10 + penWidth/2, 10 + penWidth/2);
}

void Mario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *GameWidget)
{
    myX = this->pos().x();
    myY = this->pos().y();
    painter->setBrush(Qt::red);
    QRectF myRect = new QRectF(myX, myY, myX + 5, myY + 5);
    painter->drawRect(myRect);
}

