#include "gamewidget.h"
#include "myConsts.h"
#include "mario.h"
#include <QDebug>

GameWidget::GameWidget(QApplication *application) :
    myApplication(application),
    scene(new QGraphicsScene),
    myMario(new Mario()),
    myFirstBarrier(new FirstBarrier()),
    mySecondBarrier(new SecondBarrier()),
    myThirdBarrier(new ThirdBarrier()),
    myFirstFire(new FirstFire()),
    myFirstEnemy(new FirstEnemy()),
    myMainMenu(new MainMenu(scene)),
    menuView(true),
    loser(new QGraphicsPixmapItem(QPixmap(":/GameOver.jpg"))),
    winner(new QGraphicsPixmapItem(QPixmap(":/WinGame.jpg")))
{
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
    setScene(scene);
    scene->setBackgroundBrush(Qt::yellow);
    QObject::connect(myMario, SIGNAL(lose), this, SLOT(gameOver()));
    QObject::connect(myMario, SIGNAL(win), this, SLOT(winGame()));
}

void GameWidget::newGame()
{
    menuView = false;
    for (int i = 0; i < 4; i++)
    {
        delete myMainMenu->mainMenu[i];
    }
    delete myMainMenu;
    scene->setBackgroundBrush(Qt::lightGray);
    scene->addItem(myFirstBarrier);
    scene->addItem(mySecondBarrier);
    scene->addItem(myThirdBarrier);
    scene->addItem(myMario);
    scene->addItem(myFirstFire);
    scene->addItem(myFirstEnemy);
    scene->setFocusItem(myMario);
}

void GameWidget::exitGame()
{
    myApplication->closeAllWindows();
}

void GameWidget::gameOver()
{
    delete myMario;
    delete myFirstBarrier;
    delete mySecondBarrier;
    delete myThirdBarrier;
    delete myFirstFire;
    delete myFirstEnemy;
    scene->addItem(loser);
}

void GameWidget::winGame()
{
    delete myMario;
    delete myFirstBarrier;
    delete mySecondBarrier;
    delete myThirdBarrier;
    delete myFirstFire;
    delete myFirstEnemy;
    scene->addItem(winner);
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< event->key()<<"\r"<< Qt::Key_Enter;
    switch(event->key())
    {
        case Qt::Key_Right:
        {
            if (!menuView)
            {
                myMario->isMoveRight = true;
            }
            break;
        }
        case Qt::Key_Left:
        {
            if (!menuView)
            {
                myMario->isMoveLeft = true;
            }
            break;
        }
        case Qt::Key_Space:
        {
            if (!menuView)
            {
                if (!myMario->isJumpingDown)
                    myMario->isJumpingUp = true;
            }
            break;
        }

        case Qt::Key_Up:
        {
            if (menuView)
            {
                myMainMenu->movePrev();
            }
            break;
        }

        case Qt::Key_Down:
        {
            if (menuView)
            {
                myMainMenu->moveNext();
            }
            break;
        }

        case Qt::Key_Enter: case Qt::Key_Return:
        {
            menuSelect();
            break;
        }
        case Qt::Key_Escape:
        {
            exitGame();
            break;
        }
        default:
        {
            QGraphicsView::keyPressEvent(event);
            break;
        }
    }
}

void GameWidget::menuSelect()
{
    if (menuView)
    {
        switch (myMainMenu->menuSelector)
        {
            case 0:
            {
                newGame();
                break;
            }
            case 3:
            {
                exitGame();
                break;
            }
            default:
                break;
        }
    }
}

void GameWidget::createBarrier(QRect rect)
{
    scene->addRect(rect);
}
