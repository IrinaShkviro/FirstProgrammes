#ifndef THIRDBARRIER_H
#define THIRDBARRIER_H

#include "myConsts.h"
#include "barriers.h"

class ThirdBarrier : public Barriers
{
public:
    ThirdBarrier();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    const int myWidth = 100;
    const int myHeight = 60;
};

#endif // THIRDBARRIER_H
