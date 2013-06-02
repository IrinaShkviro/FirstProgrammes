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
    Lexer()
    {
         expression = "";
         curPosition = 0;
         lengthOfExpression = expression.length();
    }

    enum LexTyper
    {
        NumberExp,
        Number,
        OpenBracket,
        CloseBracket,
        Add,
        Minus,
        Degree,
        Divide,
        Multiply,
        Eof
    };

    enum ErrorType
    {
        SemicolonIsMissed,
        ErrorInActionOrNumber,
        OpenBracketIsMissed,
        CloseBracketIsMissed,
        ErrorInVar,
        ParserError,
        DivideByZero,
        LexerError,
        NullArgument
    };

    struct Lexem
    {
        LexTyper LexType;
        double Value;
         QString Name;
    };

public:
    void Inicialization( QString expr);
    Lexem LookAhead(bool nextToken);
    Lexem GetNextToken();

private:
      QString expression;
      int curPosition;
      int lengthOfExpression;

      void MissDelimeters();
      bool IsNumber(int copyOfCurPosition);
      bool IsExpNumber(int copyOfCurPosition);

};

#endif // LEXER_H
