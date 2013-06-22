#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QGraphicsView>
#include "mario.h"
#include <QRectF>
#include <QKeyEvent>
#include "barriers.h"
#include "firstbarrier.h"
#include "secondbarrier.h"


class GameWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GameWidget(QWidget *parent = 0);
    QGraphicsScene *scene;
    void createBarrier(QRect rect);

private:
    Mario *myMario;
    Barriers *myBarriers;
    FirstBarrier *myFirstBarrier;
    SecondBarrier *mySecondBarrier;
    void keyPressEvent(QKeyEvent *event);

signals:

    
public slots:

    
};

#endif // GAMEWIDGET_H
