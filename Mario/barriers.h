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

};

#endif // BARRIERS_H
