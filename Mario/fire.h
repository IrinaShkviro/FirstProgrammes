#ifndef FIRE_H
#define FIRE_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>

#include "myConsts.h"

class Fire : public QGraphicsItem
{

public:
    Fire(int width, int height, int posX, int posY);
    enum {Type = UserType + 3};
    QRectF boundingRect() const;
    QBrush myFireBrush;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const { return Type; }

private:
    int myWidth, myHeight;

};

#endif // FIRE_H
