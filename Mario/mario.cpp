#include <QDebug>
#include "mario.h"

Mario::Mario(QGraphicsScene *scene):
    pScene(scene),
    myX(0),
    myY(sceneHeight - mySize),
    theEnd(false),
    mario(QPixmap(":/MyMario.gif")),
    myCondition(stay),
    myCollision(noCollision)
{
    this->setPixmap(mario);
    this->setScale(0.06);
    this->setPos(myX, myY);
}

bool Mario::isMoveDown()
{
    if (myCondition == rightAndDown || myCondition == leftAndDown || myCondition == down)
    {
        return true;
    }
    return false;
}

bool Mario::isMoveUp()
{
    if (myCondition == rightAndUp || myCondition == leftAndUp || myCondition == up)
    {
        return true;
    }
    return false;
}

bool Mario::isMoveRight()
{
    if (myCondition == rightAndDown || myCondition == rightAndUp || myCondition == right)
    {
        return true;
    }
    return false;
}

bool Mario::isMoveLeft()
{
    if (myCondition == leftAndDown || myCondition == leftAndUp || myCondition == left)
    {
        return true;
    }
    return false;
}

void Mario::defineTypeOfCollision(QRectF myMarioBoard, QRectF colliderBoard)
{
    if (myMarioBoard.right() >= colliderBoard.left() - 2
            && myMarioBoard.right() < colliderBoard.right()
            && !(myMarioBoard.bottom() < colliderBoard.top() + 5
                || myMarioBoard.top() + 5 > colliderBoard.bottom()))
    {
        if (myCollision == downCol)
        {
            myCollision = rightAndDownCol;
        }
        else
        {
            if (myCollision == upCol)
            {
                myCollision = rightAndUpCol;
            }
            else
            {
                myCollision = rightCol;
            }
        }
    }
    if (myMarioBoard.left() <= colliderBoard.right()
            && myMarioBoard.right() > colliderBoard.right()
            && !(myMarioBoard.bottom() <= colliderBoard.top() + 5
                            || myMarioBoard.top() + 5 >= colliderBoard.bottom()))
    {
        if (myCollision == downCol)
        {
            myCollision = leftAndDownCol;
        }
        else
        {
            if (myCollision == upCol)
            {
                myCollision = leftAndUpCol;
            }
            else
            {
                myCollision = leftCol;
            }
        }
    }
    if (myMarioBoard.top() <= colliderBoard.bottom()
            && myMarioBoard.bottom() > colliderBoard.bottom()
            && !(myMarioBoard.right() < colliderBoard.left() + 5
                || myMarioBoard.left() > colliderBoard.right() - 5))
    {
        if (myCollision == rightCol)
        {
            myCollision = rightAndUpCol;
        }
        else
        {
            if (myCollision == leftCol)
            {
                myCollision = leftAndUpCol;
            }
            else
            {
                myCollision = upCol;
            }
        }
    }
    if (myMarioBoard.bottom() >= colliderBoard.top()
            && myMarioBoard.bottom() <= colliderBoard.top() + 5
            && myMarioBoard.bottom() < colliderBoard.bottom()
            && !(myMarioBoard.right() < colliderBoard.left() + 5
                 || myMarioBoard.left() > colliderBoard.right() - 5))
    {
        if (myCollision == rightCol)
        {
            myCollision = rightAndDownCol;
        }
        else
        {
            if (myCollision == leftCol)
            {
                myCollision = leftAndDownCol;
            }
            else
            {
                myCollision = downCol;
            }
        }
    }
}

bool Mario::isDownCollision()
{
    if (myCollision == rightAndDownCol || myCollision == leftAndDownCol || myCollision == downCol)
    {
        return true;
    }
    return false;
}

bool Mario::isUpCollision()
{
    if (myCollision == rightAndUpCol || myCollision == leftAndUpCol || myCollision == upCol)
    {
        return true;
    }
    return false;
}

bool Mario::isRightCollision()
{
    if (myCollision == rightAndDownCol || myCollision == rightAndUpCol || myCollision == rightCol)
    {
        return true;
    }
    return false;
}

bool Mario::isLeftCollision()
{
    if (myCollision == leftAndDownCol || myCollision == leftAndUpCol || myCollision == leftCol)
    {
        return true;
    }
    return false;
}

void Mario::deleteDownMove()
{
    if (myCondition == leftAndDown)
    {
        myCondition = left;
    }
    else
    {
        if (myCondition== rightAndDown)
        {
            myCondition == right;
        }
        else
        {
            myCondition = stay;
        }
    }
}

void Mario::deleteUpMove()
{
    if (myCondition == leftAndUp)
    {
        myCondition = leftAndDown;
    }
    else
    {
        if (myCondition == rightAndUp)
        {
            myCondition = rightAndDown;
        }
        else
        {
            myCondition = down;
        }
    }
}

void Mario::barrierCollision()
{
    if (isUpCollision() && isMoveUp())
    {
        deleteUpMove();
    }
    if (isDownCollision() && isMoveDown())
    {
        deleteDownMove();
    }
    if (isLeftCollision() && isMoveLeft())
    {
        if (myCondition == left)
        {
            myCondition = stay;
        }
        else
        {
            myCondition = down;
        }
    }
    if (isRightCollision() && isMoveRight())
    {
        if (myCondition == right)
        {
            myCondition = stay;
        }
        else
        {
            myCondition = down;
        }
    }
}

void Mario::advance(int step)
{
    if (!step) return;

    myCollision = noCollision;
    QRectF myMarioBoard = this->sceneBoundingRect();
    QList <QGraphicsItem *> collidedItems = this->collidingItems();
    if (!collidedItems.isEmpty())
    {
        int sizeOfList = collidedItems.size();
        for (int i = 0; i < sizeOfList; i++)
        {
            QGraphicsItem *myCollider = collidedItems.at(i);
            defineTypeOfCollision(myMarioBoard, myCollider->sceneBoundingRect());

            if (myCollider->type() == Barriers::Type)
            {
                barrierCollision();
            }
            else
            {
                if (myCollider->type() == Fire::Type)
                {
                    QTimer::singleShot(5, this, SLOT(loseEmiter()));
                    theEnd = true;
                }
                else
                {
                    if (myCollider->type() == Enemy::Type)
                    {
                        if (isDownCollision())
                        {
                            pScene->removeItem(myCollider);
                            break;
                        }
                        else
                        {
                            QTimer::singleShot(5, this, SLOT(loseEmiter()));
                            theEnd = true;
                        }
                    }
                }
            }
        }
    }
    if (!theEnd)
    {
        if (isMoveUp())
        {
            if (height < 70 && myMarioBoard.top() > 5)
            {
                height += 5;
                moveBy(0, -5);
                myY -=5;
            }
            else
            {
                if (myCondition == leftAndUp)
                {
                    myCondition = leftAndDown;
                }
                else
                {
                    if (myCondition == rightAndUp)
                    {
                        myCondition = rightAndDown;
                    }
                    else
                    {
                        myCondition = down;
                    }
                }
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
            if (myMarioBoard.bottom() <= sceneHeight - 3 && !isDownCollision())
            {
                moveBy(0, 5);
                myY += 5;
            }
            else
            {
                height = 0;
                deleteDownMove();
            }
        }

        if (isMoveLeft())
        {
            if (myCondition == leftAndUp)
            {
                myCondition = up;
            }
            else
            {
                if (myCondition == leftAndDown)
                {
                    myCondition = down;
                }
                else
                {
                    myCondition = stay;
                }
            }
            if (myMarioBoard.left() > 5)
            {
                moveBy(-5, 0);
                myX -= 5;
            }
        }

        if (isMoveRight())
        {
            if (myCondition == rightAndUp)
            {
                myCondition = up;
            }
            else
            {
                if (myCondition == rightAndDown)
                {
                    myCondition = down;
                }
                else
                {
                    myCondition = stay;
                }
            }
            if (myMarioBoard.right() < sceneWidth - 5)
            {
                moveBy(5, 0);
                myX += 5;
            }
            else
            {
                QTimer::singleShot(5, this, SLOT(winEmiter()));
                theEnd = true;
            }
        }
        if (!theEnd)
        {
            this->setPos(myX, myY);
        }
    }
}

void Mario::loseEmiter()
{
    emit lose();
}

void Mario::winEmiter()
{
    emit win();
}
