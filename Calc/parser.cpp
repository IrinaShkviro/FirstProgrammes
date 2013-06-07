#include "lexer.h"
#include "mainwindow.h"
#include "parser.h"


 QString Parser::eatFactor()
 {
    if ( myLexer.lookAhead(false).lexType ==  Lexer::numberExp ||  myLexer.lookAhead(false).lexType ==  Lexer::number)
    {
        return  myLexer.getNextToken().name + '|';
    }
    if ( myLexer.lookAhead(false).lexType ==  Lexer::openBracket)
    {
        countOfBrackets++;
        myLexer.getNextToken();
        return eatExpr();
    }
    return "";
 }

 QString Parser::eatDegree()
 {
    QString current = eatFactor();
    if (current.isEmpty())
        return "";
    QString result = current;
    if ( myLexer.lookAhead(false).lexType ==  Lexer::degree)
    {
       myLexer.getNextToken();
       current = eatDegree();
       if (current.isEmpty())
        return "";
       result += current;
       result += "^";
    }
    return result;
 }

 QString Parser::eatTerm()
 {
    QString result = eatDegree();
    if (result.isEmpty())
      return "";
    while ( myLexer.lookAhead(false).lexType ==  Lexer::multiply ||  myLexer.lookAhead(false).lexType ==  Lexer::divide)
    {
      QString current;
      if ( myLexer.getNextToken().lexType ==  Lexer::multiply)
      {
          current= eatDegree();
          if (current.isEmpty())
            return "";
          result += current;
          result += "*";
      }
      else
      {
          current= eatDegree();
          if (current.isEmpty())
            return "";
          result += current;
          result += "/";
      }
    }
    return result;
 }

 QString Parser::eatExpr()
 {
    QString result = eatTerm();
    if (result.isEmpty())
       return "";
    while ( myLexer.lookAhead(false).lexType ==  Lexer::add ||  myLexer.lookAhead(false).lexType ==  Lexer::minus)
    {
       QString current;
       if ( myLexer.getNextToken().lexType ==  Lexer::add)
       {
           current= eatTerm();
           if (current.isEmpty())
              return "";
           result += current;
           result += "+";
       }
       else
       {
           current= eatTerm();
           if (current.isEmpty())
              return "";
           result += current;
           result += "-";
        }
    }
    if ( myLexer.lookAhead(false).lexType ==  Lexer::closeBracket)
    {
        countOfBrackets--;
        if (countOfBrackets < 0)
        {
           return "";
        }
        myLexer.getNextToken();
    }
    return result;
}

QString Parser::getExpr(QString expr, bool isExp)
{
    myLexer.initialization(expr);
    QString parserResult = eatExpr();
    if (parserResult.isEmpty() || countOfBrackets > 0 || myLexer.lookAhead(false).lexType != Lexer::eof)
    {
        return "";
    }
    CalculateExpression myCalculator;
    return  myCalculator.calculateExpress(parserResult, isExp);
}

