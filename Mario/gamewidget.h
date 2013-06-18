#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QGraphicsView>
#include "mario.h"
#include <QRectF>


class GameWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = 0);
    QGraphicsScene *scene;

private:
    Mario *myMario;

    
signals:
    
public slots:
    
};

#endif // GAMEWIDGET_H
