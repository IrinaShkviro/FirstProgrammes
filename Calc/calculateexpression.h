#ifndef CALCULATEEXPRESSION_H
#define CALCULATEEXPRESSION_H
#include <QString>
#include <QStack>
#include <math.h>
#include "mainwindow.h"

class CalculateExpression
{
public:
    QString CalculateExpress(QString expr, bool isExp);

private:
    MainWindow myMainWindow;
     QString expression;
     int lengthOfExpression;
     bool IsNumber(int copyOfCurPosition);
    bool IsExpon(int copyOfCurPosition);
};

#endif // CALCULATEEXPRESSION_H
