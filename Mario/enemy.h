#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include "myConsts.h"
#include <QRectF>
#include <QPainter>

class Enemy : public QObject, public QGraphicsItem
{
Q_OBJECT
public:
    Enemy();
    enum {Type = UserType + 2};
    int type() const {return Type;};

protected:
    void advance(int step);
    
};

#endif // ENEMY_H
