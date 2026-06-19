#ifndef PARSER_H
#define PARSER_H

#include "queue.h"
#include "stack.h"

//Defines Error codes
typedef enum{
  ERR_NONE,
  ERR_MISMATCH_PAREN, //Triggered in Phase 1 or 2 if there are unequal numbers of parenthesis
  ERR_INVALID_CHAR, //Triggered in Phase 1 if the string contains letters or invalid symbols ($, @, ~, etc.)
  ERR_MALFORMED, //Triggered in Phase 3 if the math is impossible
  ERR_DIV_ZERO //Trigered in Phase 3 if the algorithm tries to divide or modulo by 0
} ErrorStatus;

//Function prototypes for the main algorithms
ErrorStatus tokenize(const char* input, Queue* outputQueue);
ErrorStatus infixToPostfix(Queue* infix, Queue* postfix);
ErrorStatus evaluatePostfix(Queue* postfix, int* result);

#endif
