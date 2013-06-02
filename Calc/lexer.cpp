#include "lexer.h"



void Lexer::Inicialization(QString expr)
{
    curPosition = 0;
    expression = expr;
    lengthOfExpression = expression.length();
}

void Lexer::MissDelimeters()
{
    const QString delimeters = " \n\t";
    while (true)
    {
        if ((curPosition < lengthOfExpression) && (delimeters.contains(expression[curPosition])))
            curPosition++;
        else
            break;
    }
}

  bool Lexer::IsNumber(int copyOfCurPosition)
{
    if (copyOfCurPosition >= lengthOfExpression)
        return false;
    if (expression.at(copyOfCurPosition).isDigit())
        return true;
    return (expression[copyOfCurPosition] == negative && copyOfCurPosition + 1 < lengthOfExpression && expression.at(copyOfCurPosition + 1).isDigit());
}

bool Lexer::IsExpNumber(int copyOfCurPosition)
{
    if (copyOfCurPosition >= lengthOfExpression || expression[copyOfCurPosition] != dividorInNumber)
        return false;
    return IsNumber(copyOfCurPosition + 1);
}

Lexer::Lexem Lexer::LookAhead(bool nextToken)
{
  Lexem result;
  result.Value = 0;
  result.LexType = Lexer::Eof;
  result.Name = "";
  int digit;
  MissDelimeters();
  int copyOfCurPosition = curPosition;

  if (curPosition >= lengthOfExpression)
  {
  }
  else
  {
      digit = expression.at(copyOfCurPosition).digitValue();
      if (expression.at(copyOfCurPosition).isDigit())
      {
          while (expression.at(copyOfCurPosition).isDigit())
          {
              copyOfCurPosition++;
              if (copyOfCurPosition == lengthOfExpression)
                  break;
              digit = expression.at(copyOfCurPosition).digitValue();
          }
          result.Name = expression.mid(curPosition, copyOfCurPosition - curPosition);
          result.LexType = Number;
          if (IsExpNumber(copyOfCurPosition))
          {
              result.Name += dividorInNumber;
              copyOfCurPosition++;
              int secondStartPos = copyOfCurPosition;
              if (expression[copyOfCurPosition] == negative)
                  copyOfCurPosition++;
              digit = expression.at(copyOfCurPosition).digitValue();
              while (expression.at(copyOfCurPosition).isDigit())
              {
                  copyOfCurPosition++;
                  if (copyOfCurPosition == lengthOfExpression)
                      break;
                  digit = expression.at(copyOfCurPosition).digitValue();
              }
              result.LexType = NumberExp;
              result.Name += expression.mid(secondStartPos, copyOfCurPosition - secondStartPos);
          }
          copyOfCurPosition--;
      }
      else
      {
          switch (expression.at(curPosition).toLatin1())
          {

              case '(':
                      result.LexType = OpenBracket;
                  break;
              case ')':
                  result.LexType = CloseBracket;
                  break;
              case '+':
                  result.LexType = Add;
                  break;
              case '-':
                  result.LexType = Minus;
                  break;
              case '/':
                  result.LexType = Divide;
                  break;
              case '*':
                  result.LexType = Multiply;
                  break;
              case '^':
                  result.LexType = Degree;
                  break;
              default:
                  break;
          }


          if (result.LexType == Eof)
          {

              curPosition++;
              result = LookAhead(nextToken);
          }
      }
  }
  copyOfCurPosition++;
  if (nextToken)
      curPosition = copyOfCurPosition;
  return result;
}

  Lexer::Lexem Lexer::GetNextToken()

{
  Lexem result = LookAhead(true);
  return result;
}




