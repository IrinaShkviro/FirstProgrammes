#ifndef MARIO_H
#define MARIO_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include "myConsts.h"
#include <QTimer>
#include <QThread>
#include <QList>


class Mario : public QObject, public QGraphicsItem
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


protected:
    void advance(int step);

signals:
    
public slots:

    
};

#endif // MARIO_H
