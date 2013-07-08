#include "gamewidget.h"
#include "myConsts.h"
#include "mario.h"
#include <QDebug>

GameWidget::GameWidget(QApplication *application) :
    myApplication(application),
    scene(new QGraphicsScene),
    myMainMenu(new MainMenu(scene)),
    menuView(true)
{
    myBackgroundBrush.setTextureImage(QImage(":/Background.jpg"));
    myLoserBrush.setTextureImage(QImage(":/GameOver.jpg"));
    myWinnerBrush.setTextureImage(QImage(":/WinGame.jpg"));
    scene->setSceneRect(0, 0, sceneWidth, sceneHeight);
    setScene(scene);
    scene->setBackgroundBrush(Qt::yellow);
}

void GameWidget::newGame()
{ 
    menuView = false;
    delete myMainMenu;
    scene->clear();
    scene->setBackgroundBrush(myBackgroundBrush);
    firstBarrier = new Barriers(70, 50, 100, 550);
    secondBarrier = new Barriers(170, 80, 170, 520);
    thirdBarrier = new Barriers(100, 60, 400, 550);
    firstFire = new Fire(340, 595, 60, 5);
    firstEnemy = new Enemy(35, 750, 502, QPixmap(":/Enemy.jpg"), QPixmap(":/EnemyRotate.jpg"));
    myMario = new Mario();
    QObject::connect(myMario, SIGNAL(lose()), this, SLOT(gameOver()));
    QObject::connect(myMario, SIGNAL(win()), this, SLOT(winGame()));
    scene->addItem(firstBarrier);
    scene->addItem(secondBarrier);
    scene->addItem(thirdBarrier);
    scene->addItem(myMario);
    scene->addItem(firstFire);
    scene->addItem(firstEnemy);
}

void GameWidget::exitGame()
{
    myApplication->closeAllWindows();
}

void GameWidget::gameOver()
{
  //  scene->removeItem(firstBarrier);
    delete myMario;
    delete firstFire;
    delete firstEnemy;

    scene->setBackgroundBrush(myLoserBrush);
    menuView = true;
    myMainMenu = new MainMenu(scene);
}

void GameWidget::winGame()
{
    scene->clear();
    scene->setBackgroundBrush(myWinnerBrush);
    menuView = true;
    myMainMenu = new MainMenu(scene);
    menuView = true;
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
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
