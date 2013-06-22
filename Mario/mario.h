#ifndef MARIO_H
#define MARIO_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include "myConsts.h"
#include <QTimer>
#include <QObject>


class Mario : public QGraphicsItem
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
    
};

#endif // MARIO_H
