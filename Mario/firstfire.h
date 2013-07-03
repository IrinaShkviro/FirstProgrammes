#ifndef FIRSTFIRE_H
#define FIRSTFIRE_H

#include "fire.h"

class FirstFire : public Fire
{
public:
    FirstFire();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    const int myWidth = 60;
    const int myHeight = 5;
};

#endif // FIRSTFIRE_H
