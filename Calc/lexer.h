#ifndef LEXER_H
#define LEXER_H
#include <QString>

const QString variables = "_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const QString digits = "0123456789";
const char dividorInNumber = 'e';
const char negative = '-';

class Lexer
{
public:
    Lexer():  expression(""), curPosition(0), lengthOfExpression(expression.length())
    {
    }


    enum LexTyper
    {
        numberExp,
        number,
        openBracket,
        closeBracket,
        add,
        minus,
        degree,
        divide,
        multiply,
        eof
    };

    struct Lexem
    {
        LexTyper lexType;
        double value;
        QString name;
    };

public:
    void initialization(QString expr);
    Lexem lookAhead(bool nextToken);
    Lexem getNextToken();

private:
      QString expression;
      int curPosition;
      int lengthOfExpression;

      void missDelimeters();
      bool isNumber(int copyOfCurPosition);
      bool isExpNumber(int copyOfCurPosition);

};

#endif // LEXER_H
