#include "gamewidget.h"
#include "myConsts.h"
#include "mario.h"

GameWidget::GameWidget(QWidget *parent) :
    QGraphicsView(parent),
    scene(new QGraphicsScene),
    myMario(new Mario(100, 300))
{
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
    setScene(scene);
    scene->setBackgroundBrush(Qt::white);

    scene->addItem(myMario);
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Right:
        {
            myMario->myX += 5;
            myMario->moveBy(5, 0);
            break;
        }
        case Qt::Key_Left:
        {
            myMario->myY += 5;
            myMario->moveBy(-5, 0);
            break;
        }
        default:
        {
            QGraphicsView::keyPressEvent(event);
            break;
        }
    }
}
