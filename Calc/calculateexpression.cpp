#include "calculateexpression.h"

bool CalculateExpression::isNumber(int copyOfCurPosition)
{
    const char negative = '-';
    if (copyOfCurPosition >= lengthOfExpression)
        return false;
    if (expression.at(copyOfCurPosition).isDigit())
        return true;
    return (expression[copyOfCurPosition] == negative && copyOfCurPosition + 1 < lengthOfExpression && expression.at(copyOfCurPosition + 1).isDigit());
}
bool CalculateExpression::isExpon(int copyOfCurPosition)
{
    if (copyOfCurPosition >= lengthOfExpression)
        return false;
    const char dividorInNumber = 'e';
    if (expression[copyOfCurPosition] != dividorInNumber)
        return false;
    return isNumber(copyOfCurPosition + 1);
}

QString CalculateExpression::calculateExpress(QString expr, bool isExp)
{
    expression = expr;
    lengthOfExpression = expression.length();
    const int decimalNumber = 10;
    const char minus = '-';
    int currentPosition = 0;
    QStack<double> operands;
    while (currentPosition < lengthOfExpression)
    {
        double number = 0;
        bool parsed = false;
        while (currentPosition < lengthOfExpression && expression[currentPosition].isDigit())
        {
            number *= 10;
            number += (double)expression[currentPosition].digitValue();
            currentPosition++;
            parsed = true;
        }
        bool f = isExpon(currentPosition);
        if (f)
        {
            currentPosition ++;
            double degreeGet = 0;
            bool negative = false;
            if (expression[currentPosition] == minus)
            {
                negative = true;
                currentPosition ++;
            }
            while (expression[currentPosition].isDigit())
            {
                degreeGet *= 10;
                degreeGet += expression[currentPosition].digitValue();
                currentPosition++;
            }
            if (negative)
                degreeGet *= -1;
                number *= pow(10, degreeGet);
        }
        if (parsed)
        {
            operands.push(number);
        }
        else
        {
            double second = operands.pop();
            double first = operands.pop();
            switch (expression.at(currentPosition).toLatin1())
            {
               case '+':
                   operands.push(first + second);
                   break;
               case '-':
                   operands.push(first - second);
                   break;
               case '*':
                   operands.push(first * second);
                   break;
               case '^':
                   operands.push(pow(first, second));
                   break;
               case '/':
                   if (second != 0)
                   {
                       operands.push(first / second);
                   }
                   else
                   {
                       return "";
                   }
                   break;
               default:
                   return "";
                   break;
           }
        }
        currentPosition++;
    }
    currentPosition++;
    double result = operands.pop();
    QString resultToQString =  "";
    if (result < 0)
    {
        result = -result;
        resultToQString = "-";
    }
    if (isExp)
    {
        int degree = 0;
        double mantissa = result;
        while (mantissa >= 1)
        {
             mantissa /= decimalNumber;
             degree++;
        }
        while (mantissa < 1)
        {
             if (mantissa == 0)
                   break;
             mantissa *= decimalNumber;
             degree--;
        }
        resultToQString += QString::number(mantissa) + "e" + QString::number(degree);
    }
    else
    {
        resultToQString += QString::number(result);
    }
    return resultToQString;
}
