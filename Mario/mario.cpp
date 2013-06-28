#include "mario.h"

Mario::Mario():
    isJumpingDown(false),
    isJumpingUp(false),
    isMoveLeft(false),
    isMoveRight(false)
{
    this->setPos(2, sceneHeight - mySize - 2);
}

QRectF Mario::boundingRect() const
{
    QRectF rect(0, 0, mySize, mySize);
    return rect.adjusted(-2, -2, 2, 2);
}

void Mario::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *GameWidget)
{
    painter->setBrush(Qt::red);
    painter->drawRect(0, 0, mySize, mySize);
}

void Mario::advance(int step)
{
    if (!step) return;

    QRectF myMarioBoard = this->sceneBoundingRect();
    QList <QGraphicsItem *> collidedItems = this->collidingItems();
    bool downCollision = false;
    if (!collidedItems.isEmpty())
    {
        QGraphicsItem *myCollider = collidedItems.first();
        QRectF colliderBoard = myCollider->sceneBoundingRect();
        bool rightCollision = false, leftCollision = false, upCollision = false;
        if (myMarioBoard.right() >= colliderBoard.left()
                && myMarioBoard.right() < colliderBoard.right()
                && !(myMarioBoard.bottom() < colliderBoard.top() + 5
                    || myMarioBoard.top() + 5 > colliderBoard.bottom()))
        {
            rightCollision = true;
        }
        if (myMarioBoard.left() <= colliderBoard.right()
                && myMarioBoard.right() > colliderBoard.right()
                && !(myMarioBoard.bottom() <= colliderBoard.top() + 5
                                || myMarioBoard.top() + 5 >= colliderBoard.bottom()))
        {
            leftCollision = true;
        }
        if (myMarioBoard.top() <= colliderBoard.bottom()
                && myMarioBoard.bottom() > colliderBoard.bottom()
                && !(myMarioBoard.right() < colliderBoard.left() + 5
                    || myMarioBoard.left() > colliderBoard.right() - 5))
        {
            upCollision = true;
        }
        if (myMarioBoard.bottom() >= colliderBoard.top()
                && myMarioBoard.bottom() < colliderBoard.bottom()
                && !(myMarioBoard.right() < colliderBoard.left() + 5
                     || myMarioBoard.left() > colliderBoard.right() - 5))
        {
            downCollision = true;
        }

        if (upCollision)
        {
            isJumpingUp = false;
            isJumpingDown = true;
        }
        if (downCollision)
        {
            isJumpingDown = false;
        }
        if (leftCollision)
        {
            isMoveLeft = false;
        }
        if (rightCollision)
        {
            isMoveRight = false;
        }
    }

    if (isJumpingUp)
    {
        if (height < 70 && myMarioBoard.top() > 5)
        {
            height += 5;
            moveBy(0, -5);
        }
        else
        {
            isJumpingUp = false;
        }
    }
    else
    {
        height = 0;
        if (myMarioBoard.bottom() <= sceneHeight - 3 && !downCollision)
        {
            moveBy(0, 5);
        }
        else
        {
            isJumpingDown = false;
        }
    }

    if (isMoveLeft)
    {
        isMoveLeft = false;
        if (myMarioBoard.left() > 5)
        {
            moveBy(-5, 0);
        }
    }
    if (isMoveRight)
    {
        isMoveRight = false;
        if (myMarioBoard.right() < sceneWidth - 5)
        {
            moveBy(5, 0);
        }
    }
}
