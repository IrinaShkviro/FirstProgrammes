#include <QDebug>
#include "mario.h"

Mario::Mario():
    isJumpingDown(false),
    isJumpingUp(false),
    isMoveLeft(false),
    isMoveRight(false),
    myX(0),
    myY(sceneHeight - mySize),
    theEnd(false),
    mario(QPixmap(":/MyMario.jpg"))
{
    this->setPixmap(mario);
    this->setScale(0.06);
    this->setPos(myX, myY);
}

void Mario::advance(int step)
{
    if (!step) return;

    QRectF myMarioBoard = this->sceneBoundingRect();
    QList <QGraphicsItem *> collidedItems = this->collidingItems();
    bool downCollision = false;
    if (!collidedItems.isEmpty())
    {
        int sizeOfList = collidedItems.size();
        for (int i = 0; i < sizeOfList; i++)
        {
            QGraphicsItem *myCollider = collidedItems.at(i);
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
            if (myCollider->type() == Barriers::Type)
            {
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
            else
            {
                if (myCollider->type() == Fire::Type)
                {
               //     collidedItems.removeOne(myCollider);
                //    delete myCollider;
                    emit lose();
                    theEnd = true;
                }
                else
                {
                    if (myCollider->type() == Enemy::Type)
                    {
                        if (downCollision)
                        {
                            delete myCollider;
                            break;
                        }
                        else
                        {

                            emit lose();
                            theEnd = true;
                        }
                    }
                }
            }
        }
    }
    if (!theEnd)
    {
        if (isJumpingUp)
        {
            if (height < 70 && myMarioBoard.top() > 5)
            {
                height += 5;
                moveBy(0, -5);
                myY -=5;
            }
            else
            {
                isJumpingUp = false;
                isJumpingDown = true;
            }
        }
        else
        {
            if (height >= 5)
            {
                height -= 5;
            }
            else
            {
                height = 0;
            }
            if (myMarioBoard.bottom() <= sceneHeight - 3 && !downCollision)
            {
                moveBy(0, 5);
                myY += 5;
            }
            else
            {
                height = 0;
                isJumpingDown = false;
            }
        }

        if (isMoveLeft)
        {
            isMoveLeft = false;
            if (myMarioBoard.left() > 5)
            {
                moveBy(-5, 0);
                myX -= 5;
            }
        }
        if (isMoveRight)
        {
            isMoveRight = false;
            if (myMarioBoard.right() < sceneWidth - 5)
            {
                moveBy(5, 0);
                myX += 5;
            }
            else
            {
                emit win();
                theEnd = true;
            }
        }
        if (!theEnd)
        {
            this->setPos(myX, myY);
        }
    }
}

