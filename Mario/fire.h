#ifndef FIRE_H
#define FIRE_H

#include <QGraphicsItem>
#include "myConsts.h"
#include <QRectF>
#include <QPainter>

class Fire : public QGraphicsItem
{

public:
    Fire(int posX, int posY, int width, int height);
    enum {Type = UserType + 3};
    QRectF boundingRect() const;
    QBrush myFireBrush;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int type() const {return Type;};

private:
    int myWidth, myHeight;

};

#endif // FIRE_H
