#ifndef BARRIERS_H
#define BARRIERS_H

#include <QGraphicsItem>
#include "myConsts.h"
#include <QRectF>
#include <QPainter>


class Barriers : public QGraphicsItem
{

public:
    Barriers();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    enum {Type = UserType + 1};
    int type() const {return Type;};

};

#endif // BARRIERS_H
