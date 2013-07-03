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
#include "firstbarrier.h"
#include "secondbarrier.h"
#include "thirdbarrier.h"
#include "firstfire.h"
#include "firstenemy.h"
#include "headmenu.h"
#include "mainmenu.h"


class GameWidget : public QGraphicsView
{
    Q_OBJECT
public:
    GameWidget(QApplication *application);
    QGraphicsScene *scene;
    void createBarrier(QRect rect);
    bool menuView;

private:
    QApplication *myApplication;
    Mario *myMario;
    Barriers *myBarriers;
    FirstBarrier *myFirstBarrier;
    SecondBarrier *mySecondBarrier;
    ThirdBarrier *myThirdBarrier;
    FirstFire *myFirstFire;
    FirstEnemy *myFirstEnemy;
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
