#include "firstenemy.h"

FirstEnemy::FirstEnemy():
    rightBoard(750),
    leftBoard(502),
    isMoveRight(true)
{
    this->setPos(leftBoard, sceneHeight - mySize + 2);
}
QRectF FirstEnemy::boundingRect() const
{
    QRectF rect(0, 0, mySize, mySize);
    return rect.adjusted(-2, -2, 2, 2);
}

void FirstEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::green);
    painter->drawRect(0, 0, mySize, mySize);
}

void FirstEnemy::advance(int step)
{
    if (!step) return;
    if (isMoveRight)
    {
        if (this->sceneBoundingRect().right() < rightBoard - 7)
        {
            this->moveBy(7, 0);
        }
        else
        {
            isMoveRight = false;
        }
    }
    else
    {
        if (this->sceneBoundingRect().left() > leftBoard + 7)
        {
            this->moveBy(-7, 0);
        }
        else
        {
            isMoveRight = true;
        }
    }
}
