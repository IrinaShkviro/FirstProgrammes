#ifndef FIRSTBARRIER_H
#define FIRSTBARRIER_H

#include "barriers.h"

class FirstBarrier : public Barriers
{
public:
    FirstBarrier();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    const int myWidth = 70;
    const int myHeight = 50;
};

#endif // FIRSTBARRIER_H
