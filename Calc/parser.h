#pragma once
#include "lexer.h"
#include "calculateexpression.h"

class Parser
{
public:
    Parser(): countOfBrackets(0)
    {
    }

     QString getExpr(QString expr, bool isExp);

private:
     Lexer myLexer;
     int countOfBrackets;
     QString eatFactor();
     QString eatDegree();
     QString eatTerm();
     QString eatExpr();
     QString eatAssign();

};

