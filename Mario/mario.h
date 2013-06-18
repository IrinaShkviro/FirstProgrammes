#ifndef MARIO_H
#define MARIO_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class Mario : public QGraphicsItem
{
public:
    Mario();
    QRectF boundingRect();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:

    
};

#endif // MARIO_H
