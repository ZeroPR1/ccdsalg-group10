#ifndef TOKEN_H
#define TOKEN_H

#define MAX_TOKENS 150 

// Defines different types of tokens in an expression
typedef enum 
{
    TOKEN_OPERAND,  // Numbers (1, 2, 3, etc.)
    TOKEN_OPERATOR, // Operators (+, -, *, /, etc.)
    TOKEN_LPAREN,   // Left parenthesis "("
    TOKEN_RPAREN    // Right parenthesis ")"
} TokenType;

// Token Structure for the Stack and Queue
typedef struct 
{
    TokenType type;
    int value;
    char symbol;
} Token;

#endif
