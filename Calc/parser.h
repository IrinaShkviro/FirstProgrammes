#pragma once
#include "lexer.h"
#include "calculateexpression.h"

class Parser
{
public:
    Parser()
    {
        countOfBrackets = 0;
    }

     QString GetExpr(QString expr, bool isExp);

private:
     Lexer myLexer;
     int countOfBrackets;
     QString EatFactor();
     QString EatDegree();
     QString EatTerm();
     QString EatExpr();
     QString EatAssign();

};

