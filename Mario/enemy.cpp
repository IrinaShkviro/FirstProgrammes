#include "enemy.h"

Enemy::Enemy(int size, int rightBoard, int leftBoard, QPixmap enemy, QPixmap enemyRotate):
myRightBoard(rightBoard),
myLeftBoard(leftBoard),
mySize(size),
isMoveRight(true),
myEnemy(enemy),
myEnemyRotate(enemyRotate)
{
    this->setPixmap(myEnemy);
    this->setScale(0.06);
    this->setPos(myLeftBoard, sceneHeight - mySize + 2);
}

void Enemy::advance(int step)
{
    if (!step) return;
    if (isMoveRight)
    {
        if (this->sceneBoundingRect().right() < myRightBoard - 7)
        {
            this->moveBy(7, 0);
        }
        else
        {
            isMoveRight = false;
            this->setPixmap(myEnemyRotate);
        }
    }
    else
    {
        if (this->sceneBoundingRect().left() > myLeftBoard + 7)
        {
            this->moveBy(-7, 0);
        }
        else
        {
            isMoveRight = true;
            this->setPixmap(myEnemy);
        }
    }
}
