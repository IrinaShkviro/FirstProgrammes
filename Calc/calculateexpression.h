#ifndef CALCULATEEXPRESSION_H
#define CALCULATEEXPRESSION_H
#include <QString>
#include <QStack>
#include <math.h>
#include "mainwindow.h"

class CalculateExpression
{
public:
    QString calculateExpress(QString expr, bool isExp);

private:
    MainWindow myMainWindow;
     QString expression;
     int lengthOfExpression;
     bool isNumber(int copyOfCurPosition);
    bool isExpon(int copyOfCurPosition);
};

#endif // CALCULATEEXPRESSION_H
