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
    bool isJumpingUp, isJumpingDown, isMoveRight, isMoveLeft;

private:
    QGraphicsScene *pScene;
    const int mySize = 30;
    int height;
    int myX, myY;
    bool theEnd;
    QPixmap mario;

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
