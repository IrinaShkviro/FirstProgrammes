#include <QApplication>
#include "gamewidget.h"
#include "myConsts.h"
#include <QTimer>
#include "headmenu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameWidget view(&a);
    view.setFixedSize(sceneWidth + 2, sceneHeight + 2);
    view.show();

    //  HeadMenu *myHeadMenu = new HeadMenu();

    QTimer myTimer;
    QObject::connect(&myTimer, SIGNAL(timeout()), view.scene, SLOT(advance()));
    myTimer.start(40);

    return a.exec();
}
