#ifndef MARIO_H
#define MARIO_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include "myConsts.h"
#include <QTimer>
#include <QThread>


class Mario : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Mario();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void space();

private:
    const int mySize = 30;

signals:
    
public slots:
    void jump();
    void down();
    
};

#endif // MARIO_H
