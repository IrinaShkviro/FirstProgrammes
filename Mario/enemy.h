#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "myConsts.h"
#include <QRectF>
#include <QPainter>
#include <QRectF>
#include <QPixmap>

class Enemy : public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Enemy(int size, int rightBoard, int leftBoard, QPixmap enemy, QPixmap enemyRotate);
    enum {Type = UserType + 2};
    int type() const {return Type;};

private:
    int mySize, myRightBoard, myLeftBoard;
    bool isMoveRight;
    QPixmap myEnemy;
    QPixmap myEnemyRotate;

protected:
    void advance(int step);
    
};

#endif // ENEMY_H
