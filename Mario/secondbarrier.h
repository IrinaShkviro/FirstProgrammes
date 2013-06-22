#ifndef SECONDBARRIER_H
#define SECONDBARRIER_H

#include "myConsts.h"
#include "barriers.h"

class SecondBarrier : public Barriers
{
public:
    SecondBarrier();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    const int myWidth = 170;
    const int myHeight = 30;
};

#endif // SECONDBARRIER_H
