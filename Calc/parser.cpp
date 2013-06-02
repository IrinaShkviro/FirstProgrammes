#include "lexer.h"
#include "mainwindow.h"
#include "parser.h"


 QString Parser::EatFactor()
            {
                if ( myLexer.LookAhead(false).LexType ==  Lexer::NumberExp ||  myLexer.LookAhead(false).LexType ==  Lexer::Number)
                {
                    return  myLexer.GetNextToken().Name + '|';
                }
                if ( myLexer.LookAhead(false).LexType ==  Lexer::OpenBracket)
                {
                    countOfBrackets++;
                     myLexer.GetNextToken();
                    return EatExpr();
                }
                return "";
            }

 QString Parser::EatDegree()
            {
                QString current = EatFactor();
                if (current == "")
                    return "";
                QString result = current;
                if ( myLexer.LookAhead(false).LexType ==  Lexer::Degree)
                {
                     myLexer.GetNextToken();
                    current = EatDegree();
                    if (current == "")
                        return "";
                    result += current;
                    result += "^";
                }
                return result;
            }

 QString Parser::EatTerm()
            {
                QString result = EatDegree();
                if (result == "")
                    return "";
                while ( myLexer.LookAhead(false).LexType ==  Lexer::Multiply ||  myLexer.LookAhead(false).LexType ==  Lexer::Divide)
                {
                    QString current;
                    if ( myLexer.GetNextToken().LexType ==  Lexer::Multiply)
                    {
                        current= EatDegree();
                        if (current == "")
                            return "";
                        result += current;
                        result += "*";
                    }
                    else
                    {
                        current= EatDegree();
                        if (current == "")
                            return "";
                        result += current;
                        result += "/";
                    }
                }
                return result;
            }

 QString Parser::EatExpr()
            {
                QString result = EatTerm();
                if (result == "")
                    return "";
                while ( myLexer.LookAhead(false).LexType ==  Lexer::Add ||  myLexer.LookAhead(false).LexType ==  Lexer::Minus)
                {
                    QString current;
                    if ( myLexer.GetNextToken().LexType ==  Lexer::Add)
                    {
                        current= EatTerm();
                        if (current == "")
                            return "";
                        result += current;
                        result += "+";
                    }
                    else
                    {
                        current= EatTerm();
                        if (current == "")
                            return "";
                        result += current;
                        result += "-";
                    }
                }
                if ( myLexer.LookAhead(false).LexType ==  Lexer::CloseBracket)
                {
                    countOfBrackets--;
                    if (countOfBrackets < 0)
                    {
                        return "";
                    }
                     myLexer.GetNextToken();
                }

                return result;
            }

QString Parser::GetExpr(QString expr, bool isExp)
{
    myLexer.Inicialization(expr);
    QString parserResult = EatExpr();
    if (parserResult == "" || countOfBrackets > 0 || myLexer.LookAhead(false).LexType != Lexer::Eof)
    {
        return "";
    }

    CalculateExpression myCalculator;

    return  myCalculator.CalculateExpress(parserResult, isExp);
}

