#ifndef FIRE_H
#define FIRE_H

#include <QGraphicsItem>
#include "myConsts.h"
#include <QRectF>
#include <QPainter>

class Fire : public QGraphicsItem
{

public:
    Fire();
    enum {Type = UserType + 3};
    int type() const {return Type;};

};

#endif // FIRE_H
