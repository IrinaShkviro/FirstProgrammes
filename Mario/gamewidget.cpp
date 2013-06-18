#include "gamewidget.h"
#include "myConsts.h"
#include "mario.h"

GameWidget::GameWidget(QWidget *parent) :
    QGraphicsView(parent),
    scene(new QGraphicsScene),
    myMario(new Mario)
{
    //myMario = new Mario();
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
    setScene(scene);
    scene->setBackgroundBrush(Qt::white);

    //scene->addItem(myMario);
}
