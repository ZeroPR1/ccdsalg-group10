#include <string.h>
#include <math.h>
#include "parser.h"

int isSpaceCustom(char c){ //checks if the char has whitespace
  int result = 0;
  if(c == ' ' || c == '\t' || c == '\n' || c == '\r'){
      result = 1;
  }
  return result;
}

int isDigitCustom(char c){
  int result = 0;
  if (c >= '0' && c <= '9'){
      result = 1;
  }
  return result;
}

ErrorStatus tokenize(const char* input,  Queue* outputQueue){
    ErrorStatus status = ERR_NONE; //start of with no errors
    int i = 0; //intializes the index counter to 0
    int len = strlen(input); //calculate the total number of characters
    int keepGoing = 1; //assigned variable to control the main loop

  //loop continues as long as we haven't reached the end and no errors have triggered it to stop
    while (i < len && keepGoing == 1){
      char c = input[i]; //extracts the single character at the current index
      if (isSpaceCustom(c)){ //skips spaces
        i = i + 1; //move the index forward to ignore the space
      }
      else if (isDigitCustom(c)){ //parses multi digit numbers
            int num = 0; //temporary variable to build our full integer

      //loop while we havent reached the end and the current character is a digit
      while  (i < len && isDigitCustom(input[i])){
        
        //multiplies the current number by 10 to shift digits left, then add the actual integer value
        num = (num * 10) + (input[i] - '0');
        i = i + 1; //moves on to the next character
        }
        Token t; //declares a new token
        t.type = TOKEN_OPERAND; //set type to signify its a number
        t.value = num; //store the fully built integer
        t.symbol = '\0'; //null character since numbers dont use symbols
        Enqueue(outputQueue, t);
      }

      //parses left parenthesis
      else if(c == '('){
        Token t;
        t.type = TOKEN_LPAREN;
        t.value = 0;
        t.symbol = c;
        Enqueue(outputQueue, t);    
        i = i + 1;
      }
        
      //parses right parenthesis
      else if(c == ')'){
        Token t;
        t.type = TOKEN_RPAREN;
        t.value = 0;
        t.symbol = c;
        Enqueue(outputQueue, t);    
        i = i + 1;
      }

      //parses operators
      else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^'){
        Token t;
        t.type = TOKEN_OPERATOR;
        t.value = 0;
        t.symbol = c;
        Enqueue(outputQueue, t);    
        i = i + 1;        
      }

      //catches invalid characters
      else {
        status = ERR_INVALID_CHAR;
        keepGoing = 0; // kills the loop
      }
    }
  
  return status;
}

int getPrecedence(char op){
  int prec = -1;
  if (op == '+' || op == '-'){
    prec = 1; //lowest
  } else if (op == '*' || op =='/' || op == '%'){
    prec = 2; //middle
  } else if (op == '^'){
    prec = 3; //highest
  }
  return prec;
}

int isRightAssociative(char op){
  int isRight = 0;
  if (op == '^'){
    isRight = 1; //exponentiation is right to left
  }
  return isRight;
}

ErrorStatus infixToPostfix(Queue* infix, Queue* postfix){
  ErrorStatus status = ERR_NONE;
  Stack opStack = CreateStack(); //Uses CreateStack from stack.c
  int keepGoing = 1;

  while (!isEmptyQueue(infix) && keepGoing == 1){
    Token t = Dequeue(infix);

    if (t.type == TOKEN_OPERAND){
      Enqueue(postfix, t);
    }
    else if (t.type == TOKEN_LPAREN){
      Push(&opStack, t);
    }
    else if (t.type == TOKEN_OPERATOR){
      int processingOps = 1;
      while (!isEmptyStack(&opStack) && processingOps == 1){
        Token topOp = Top(&opStack);

        if (topOp.type == TOKEN_OPERATOR){
          int precT = getPrecedence(t.symbol);
          int precTop = getPrecedence(topOp.symbol);
          int isRightAssoc = isRightAssociative(t.symbol);

          if ((!isRightAssoc && precT <= precTop) || (isRightAssoc && precT < precTop)){
            Enqueue(postfix, Pop(&opStack));
          } else {
            processingOps = 0;
          }
        } else {
          processingOps = 0;
        }
      }

      Push(&opStack, t);
    }
    else if (t.type == TOKEN_RPAREN){
      int foundLparen = 0;
      while (!isEmptyStack(&opStack) && foundLparen == 0){
        Token popped = Pop(&opStack);
        if (popped.type == TOKEN_LPAREN){
          foundLparen = 1;
        } else {
          Enqueue(postfix, popped);
        }
      }

      if (foundLparen == 0){
        status = ERR_MISMATCH_PAREN;
        keepGoing = 0;
      }
    }
  }

  while(!isEmptyStack(&opStack) && keepGoing == 1){
    Token popped = Pop(&opStack);

    if (popped.type == TOKEN_LPAREN || popped.type == TOKEN_RPAREN){
      status = ERR_MISMATCH_PAREN;
      keepGoing = 0;
    } else {
      Enqueue(postfix, popped);
    }
  }

  return status;
}

ErrorStatus evaluatePostfix(Queue* postfix, int* result){
  ErrorStatus status = ERR_NONE;
  Stack evalStack = CreateStack();
  int keepGoing = 1;

  while (!isEmptyQueue(postfix) && keepGoing == 1){
    Token t = Dequeue(postfix);

    if (t.type == TOKEN_OPERAND){
      Push(&evalStack, t);
    }

    else if(t.type == TOKEN_OPERATOR){
      if (evalStack.top < 1){
        status = ERR_MALFORMED;
        keepGoing = 0;
      } else {
        Token rightToken = Pop(&evalStack);
        Token leftToken = Pop(&evalStack);

        int right = rightToken.value;
        int left = leftToken.value;
        int calcResult = 0;
        int calcSuccess = 1;

        switch (t.symbol){
          case '+': calcResult = left + right; break;
          case '-': calcResult = left - right; break;
          case '*': calcResult = left * right; break;
          case '^': calcResult = (int)pow(left, right); break;
          case '/':
              if (right == 0){
                status = ERR_DIV_ZERO;
                calcSuccess = 0;
                keepGoing = 0;
              } else {
                calcResult = left / right;
              }
              break;
          case '%':
              if (right == 0){
                status = ERR_DIV_ZERO;
                calcSuccess = 0;
                keepGoing = 0;
              } else {
                calcResult = left % right;
              }
              break;
        }

        if (calcSuccess == 1){
          Token resToken;
          resToken.type = TOKEN_OPERAND;
          resToken.value = calcResult;
          resToken.symbol = '\0';
          Push(&evalStack, resToken);
        }
      }
    }
  }

  if(keepGoing == 1){
    if (evalStack.top == 0){
      Token finalToken = Pop(&evalStack);
      *result = finalToken.value;
    } else {
      status = ERR_MALFORMED;
    }
  }

  return status;
}
