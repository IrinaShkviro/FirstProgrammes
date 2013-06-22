#include "gamewidget.h"
#include "myConsts.h"
#include "mario.h"

GameWidget::GameWidget(QWidget *parent) :
    QGraphicsView(parent),
    scene(new QGraphicsScene),
    myMario(new Mario()),
    myFirstBarrier(new FirstBarrier()),
    mySecondBarrier(new SecondBarrier())
{
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
    setScene(scene);
    scene->setBackgroundBrush(Qt::white);

    scene->addItem(myFirstBarrier);
    scene->addItem(mySecondBarrier);
    scene->addItem(myMario);
    scene->setFocusItem(myMario);
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Right:
        {
            myMario->moveBy(5, 0);
            break;
        }
        case Qt::Key_Left:
        {
            myMario->moveBy(-5, 0);
            break;
        }
        case Qt::Key_Space:
        {
            myMario->space();
            break;
        }
        default:
        {
            QGraphicsView::keyPressEvent(event);
            break;
        }
    }
}

void GameWidget::createBarrier(QRect rect)
{
    scene->addRect(rect);
}
