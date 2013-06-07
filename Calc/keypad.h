#ifndef KEYPAD_H
#define KEYPAD_H

#include <QWidget>
#include <QSignalMapper>
#include <QPushButton>
#include <QGridLayout>
#include "mainwindow.h"

class KeyPad : public MainWindow
{
    Q_OBJECT

public:
    explicit KeyPad(MainWindow *parent = 0);
    
signals:
    void digitClicked(int i);
    
public slots:

private:
    QPushButton *buttons[10];
    void createLayout();
    
};

#endif // KEYPAD_H
