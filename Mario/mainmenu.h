#ifndef MAINMENU_H
#define MAINMENU_H

#include "menu.h"
#include <QFont>

class MainMenu : public Menu
{

public:
    MainMenu(QGraphicsScene* scene);
    void setMainMenu();
    void pushMenuText();
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
