#ifndef HEADMENU_H
#define HEADMENU_H

#include "menu.h"

class HeadMenu : public Menu
{

public:
    HeadMenu(QWidget *parent);
    QAction* newAct;
    QAction* openAct;
    QAction* exitAct;
    QAction* helpAct;

private:
    QWidget* p;
    QMenu* fileMenu;
    QMenu* editMenu;
    QMenu* makingMenu;
    QMenu* debugMenu;
    QMenu* helpMenu;
    QMenu* aboutMenu;

    void createMenuBar();
    void createActions();
    
};

#endif // MENU_H
