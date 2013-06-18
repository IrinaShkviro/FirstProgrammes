#include <QApplication>
#include "gamewidget.h"
#include "myConsts.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWidget view;
    view.setFixedSize(sceneWidth + 2, sceneHeight + 2);
    view.show();

    QTimer myTimer;
    QObject::connect(&myTimer, SIGNAL(timeout()), view.scene, SLOT(advance()));
    myTimer.start(40);

    return a.exec();
}
