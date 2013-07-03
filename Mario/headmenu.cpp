#include "headmenu.h"

HeadMenu::HeadMenu(QWidget *parent)
{
    p = parent;
    createMenuBar();
   /* this->setTearOffEnabled(true);
    this->addAction("&New game", this, SLOT(newGame()));
    QMenu* myMenuSubMenu = new QMenu("&Load game", this);
    this->addMenu(myMenuSubMenu);
    myMenuSubMenu->addAction("&1");
    myMenuSubMenu->addAction("&2");

    this->addAction("&Exit", this, SLOT(quit()));*/
}

void HeadMenu::createActions()
{
    newAct = new QAction(tr("&New"), p);
    newAct->setShortcut(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));

    openAct = new QAction(tr("&Open"), p);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip("Open a file");

    helpAct = new QAction(tr("Help"), p);
    helpAct->setShortcut(tr("F1"));
    helpAct->setStatusTip(tr("Help"));

    exitAct = new QAction(tr("E&xit"), p);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
}

void HeadMenu::createMenuBar()
{
    createActions();

    fileMenu = new QMenu(tr("&File"), p);
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(exitAct);

    this->addMenu(fileMenu);

    editMenu = new QMenu(tr("&Edit"), p);
    this->addMenu(editMenu);

    makingMenu = new QMenu(tr("Making"), p);
    this->addMenu(makingMenu);

    debugMenu = new QMenu(tr("Debug"), p);
    this->addMenu(debugMenu);

    helpMenu = new QMenu(tr("Help"), p);
    helpMenu->addAction(helpAct);
    this->addMenu(helpMenu);

    aboutMenu = new QMenu(tr("About"), p);
    this->addMenu(aboutMenu);
}
