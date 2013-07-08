#include "mainmenu.h"

MainMenu::MainMenu(QGraphicsScene* scene) :
    pScene(scene),
    menuSelector(0)
{
    for (int i = 0; i < 4; i++)
    {
        mainMenu[i] = new QGraphicsTextItem();
    }
    myFont.setBold(true);
    this->setMainMenu();
}

void MainMenu::setMainMenu()
{
    setMainMenuText(mainMenu[0], 300, sceneHeight / 4, "New Game");
    mainMenu[0]->setFont(myFont);
    setMainMenuText(mainMenu[1], 300, 3 * sceneHeight / 8, "Records");
    setMainMenuText(mainMenu[2], 300, sceneHeight / 2, "Help me, please");
    setMainMenuText(mainMenu[3], 300, 5 * sceneHeight/8, "Exit Game");
}

void MainMenu::setMainMenuText(QGraphicsTextItem *mainMenuText, int posX, int posY, QString text)
{
    mainMenuText->setHtml(text);
    mainMenuText->setFont(QFont("Terminus"));
    mainMenuText->setPos(posX, posY);
    pScene->addItem(mainMenuText);
}

void MainMenu::moveNext()
{
    mainMenu[menuSelector]->setFont(QFont("Terminus"));
    if (menuSelector < 3)
    {
        menuSelector ++;
    }
    else
    {
        menuSelector = 0;
    }
    mainMenu[menuSelector]->setFont(myFont);
}

void MainMenu::movePrev()
{
    mainMenu[menuSelector]->setFont(QFont("Terminus"));
    if (menuSelector > 0)
    {
        menuSelector --;
    }
    else
    {
        menuSelector = 3;
    }
    mainMenu[menuSelector]->setFont(myFont);
}

MainMenu::~MainMenu()
{
    for (int i = 0; i < 4; i++)
    {
        delete mainMenu[i];
    }
}
