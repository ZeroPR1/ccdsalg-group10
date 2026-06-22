#ifndef TOKEN_H
#define TOKEN_H

// Can be adjusted as needed
#define MAX_TOKENS 10000  // Max tokens
#define MAX_INPUT 30000 // Max user input

// Defines different types of tokens in an expression
typedef enum 
{
    TOKEN_OPERAND,  // Numbers (1, 2, 3, etc.)
    TOKEN_OPERATOR, // Operators (+, -, *, /, etc.)
    TOKEN_LPAREN,   // Left parenthesis "("
    TOKEN_RPAREN    // Right parenthesis ")"
} TokenTypes;

// Token Structure for the Stack and Queue
typedef struct 
{
    TokenTypes type;
    int value;
    char symbol;
} Token;

#endif
