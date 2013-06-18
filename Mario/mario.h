#ifndef MARIO_H
#define MARIO_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

class Mario : public QGraphicsItem
{
public:
    Mario(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int myX, myY;

private:

};

#endif // MARIO_H
