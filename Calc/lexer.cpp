#include "lexer.h"



void Lexer::initialization(QString expr)
{
    curPosition = 0;
    expression = expr;
    lengthOfExpression = expression.length();
}

void Lexer::missDelimeters()
{
    const QString delimeters = " \n\t";
    while ((curPosition < lengthOfExpression) && (delimeters.contains(expression[curPosition])))
    {
        curPosition++;
    }
}

  bool Lexer::isNumber(int copyOfCurPosition)
{
    if (copyOfCurPosition >= lengthOfExpression)
        return false;
    if (expression.at(copyOfCurPosition).isDigit())
        return true;
    return (expression[copyOfCurPosition] == negative && copyOfCurPosition + 1 < lengthOfExpression && expression.at(copyOfCurPosition + 1).isDigit());
}

bool Lexer::isExpNumber(int copyOfCurPosition)
{
    if (copyOfCurPosition >= lengthOfExpression || expression[copyOfCurPosition] != dividorInNumber)
        return false;
    return isNumber(copyOfCurPosition + 1);
}

Lexer::Lexem Lexer::lookAhead(bool nextToken)
{
  Lexem result;
  result.value = 0;
  result.lexType = Lexer::eof;
  result.name = "";
  missDelimeters();
  int copyOfCurPosition = curPosition;

  if (curPosition < lengthOfExpression)
  {
      if (expression.at(copyOfCurPosition).isDigit())
      {
          while (expression.at(copyOfCurPosition).isDigit())
          {
              copyOfCurPosition++;
              if (copyOfCurPosition == lengthOfExpression)
                  break;
          }
          result.name = expression.mid(curPosition, copyOfCurPosition - curPosition);
          result.lexType = number;
          if (isExpNumber(copyOfCurPosition))
          {
              result.name += dividorInNumber;
              copyOfCurPosition++;
              int secondStartPos = copyOfCurPosition;
              if (expression[copyOfCurPosition] == negative)
                  copyOfCurPosition++;
              while (expression.at(copyOfCurPosition).isDigit())
              {
                  copyOfCurPosition++;
                  if (copyOfCurPosition == lengthOfExpression)
                      break;
              }
              result.lexType = numberExp;
              result.name += expression.mid(secondStartPos, copyOfCurPosition - secondStartPos);
          }
          copyOfCurPosition--;
      }
      else
      {
          switch (expression.at(curPosition).toLatin1())
          {

              case '(':
                      result.lexType = openBracket;
                  break;
              case ')':
                  result.lexType = closeBracket;
                  break;
              case '+':
                  result.lexType = add;
                  break;
              case '-':
                  result.lexType = minus;
                  break;
              case '/':
                  result.lexType = divide;
                  break;
              case '*':
                  result.lexType = multiply;
                  break;
              case '^':
                  result.lexType = degree;
                  break;
              default:
                  break;
          }


          if (result.lexType == eof)
          {

              curPosition++;
              result = lookAhead(nextToken);
          }
      }
  }
  copyOfCurPosition++;
  if (nextToken)
      curPosition = copyOfCurPosition;
  return result;
}

  Lexer::Lexem Lexer::getNextToken()

{
  Lexem result = lookAhead(true);
  return result;
}




