#include "keypad.h"
#include "mainwindow.h"
#include <QGridLayout>

KeyPad::KeyPad(MainWindow *parent) :
    MainWindow(parent)
{
    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SIGNAL(digitClicked(int)));
    for (int i = 0; i < 10; i++)
    {
        buttons[i] = new QPushButton(QString::number(i), this);
        signalMapper->setMapping(buttons[i], i);
        connect(buttons[i], SIGNAL(clicked()), this, SLOT(map()));
    }
    createLayout();

}

void KeyPad::digitClicked(int i)
{
}

void KeyPad::createLayout()
    {
        QGridLayout *layout = new QGridLayout();
        layout->setMargin(6);
        layout->setSpacing(6);

        for (int i = 0; i < 9; ++i)
            layout->addWidget(buttons[i + 1], i / 3, i % 3);
        layout->addWidget(buttons[0], 3, 1);
    }
