#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QGraphicsView>
#include <QApplication>
#include "mario.h"
#include <QRectF>
#include <QKeyEvent>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "barriers.h"
#include "enemy.h"
#include "fire.h"
#include "headmenu.h"
#include "mainmenu.h"


class GameWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GameWidget(QApplication *application);
    QGraphicsScene *scene;
    bool menuView;

private:
    QApplication *myApplication;
    Mario *myMario;
    Barriers *firstBarrier;
    Barriers *secondBarrier;
    Barriers *thirdBarrier;
    Fire *firstFire;
    Fire *secondFire;
    Enemy *firstEnemy;
    MainMenu *myMainMenu;
    QGraphicsPixmapItem *loser;
    QGraphicsPixmapItem *winner;
    void keyPressEvent(QKeyEvent *event);
    void menuSelect();
    void newGame();
    void exitGame();

signals:

    
public slots:
    void gameOver();
    void winGame();
    
};

#endif // GAMEWIDGET_H
