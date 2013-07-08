#ifndef MARIO_H
#define MARIO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QRectF>
#include <QPainter>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QThread>
#include <QList>

#include "myConsts.h"
#include "barriers.h"
#include "fire.h"
#include "enemy.h"


class Mario : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Mario(QGraphicsScene *scene);
    enum moveCondition
    {
        right,
        left,
        down,
        up,
        rightAndDown,
        leftAndDown,
        rightAndUp,
        leftAndUp,
        stay
    };
    moveCondition myCondition;

   enum collisionType
   {
       rightCol,
       leftCol,
       downCol,
       upCol,
       rightAndUpCol,
       leftAndUpCol,
       rightAndDownCol,
       leftAndDownCol,
       noCollision
   };
   collisionType myCollision;
   bool isMoveDown();
   bool isMoveUp();
   bool isMoveLeft();
   bool isMoveRight();

private:
    QGraphicsScene *pScene;
    const int mySize = 30;
    int height;
    int myX, myY;
    bool theEnd;
    QPixmap mario;
    void defineTypeOfCollision(QRectF myMarioBoard, QRectF colliderBoard);
    bool isUpCollision();
    bool isDownCollision();
    bool isRightCollision();
    bool isLeftCollision();
    void barrierCollision();
    void deleteDownMove();
    void deleteUpMove();

protected:
    void advance(int step);

signals:
    void lose();
    void win();
    
public slots:
    void loseEmiter();
    void winEmiter();
    
};

#endif // MARIO_H
