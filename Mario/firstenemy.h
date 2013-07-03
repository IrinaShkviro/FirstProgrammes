#ifndef FIRSTENEMY_H
#define FIRSTENEMY_H

#include "enemy.h"

class FirstEnemy : public Enemy
{
public:
    FirstEnemy();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool isMoveRight;

private:
    const int mySize = 35;

protected:
    void advance(int step);
    int leftBoard = 502, rightBoard = 750;

};

#endif // FIRSTENEMY_H
