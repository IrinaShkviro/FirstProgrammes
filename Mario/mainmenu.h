#ifndef MAINMENU_H
#define MAINMENU_H

#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsTextItem>

#include "myConsts.h"

class MainMenu
{

public:
    MainMenu(QGraphicsScene* scene);
    ~MainMenu();
    void setMainMenu();
    QGraphicsTextItem *mainMenu[4];
    int menuSelector;
    QFont myFont;
    void moveNext();
    void movePrev();

private:
    QGraphicsScene* pScene;

    void setMainMenuText(QGraphicsTextItem *mainMenuText,int posX, int posY, QString text);
    
};

#endif // MAINMENU_H
