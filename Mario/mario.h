#ifndef MARIO_H
#define MARIO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QRectF>
#include <QPainter>
#include "myConsts.h"
#include <QTimer>
#include <QThread>
#include <QList>
#include "barriers.h"
#include "fire.h"


class Mario : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Mario();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool isJumpingUp, isJumpingDown, isMoveRight, isMoveLeft;

private:
    const int mySize = 30;
    int height;
    int myX, myY;
    bool theEnd;


protected:
    void advance(int step);

signals:
    void lose();
    void win();
    
public slots:

    
};

#endif // MARIO_H
