#ifndef BARRIERS_H
#define BARRIERS_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

#include "myConsts.h"


class Barriers : public QGraphicsItem
{

public:
    Barriers(int width, int height, int posX, int posY);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QBrush myBarrierBrush;

    enum {Type = UserType + 1};
    int type() const { return Type; }

private:
    int myWidth, myHeight;

};

#endif // BARRIERS_H
