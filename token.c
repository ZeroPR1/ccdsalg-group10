
// NOTE TO SELF: Try to finish MCO1 after wednesday exam
#ifndef CCDSALG_H
#define CCDSALG_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_PARENTHESIS,
    TOKEN_EMPTY 
} TokenType;

typedef struct {
    TokenType type;
    long long value; // For multi-digit integers 
    char symbol;     // Stores operators / parentheses
} Token;

// Node
typedef struct Node 
{
    Token data;
    struct Node* next;
} Node;

// Stack Struct
typedef struct
 {
    Node* top;
    int size;
} Stack;

// Queue
typedef struct 
{
    Node* head;
    Node* tail;
    int size;
} Queue;


// Stack Function Prototypes
void initStack(Stack* s);
void pushStack(Stack* s, Token t);
Token popStack(Stack* s);
Token peekStack(Stack* s);
void freeStack(Stack* s);

// Queue unction Prototypes
void initQueue(Queue* q);
void enqueue(Queue* q, Token t);
Token dequeue(Queue* q);
Token peekQueue(Queue* q);
void freeQueue(Queue* q);

int tokenizeExpression(const char* expr, Queue* tokenQueue);
int convertInfixToPostfix(Queue* infixQueue, Queue* postfixQueue);
int evaluatePostfix(Queue* postfixQueue, long long* outResult);

#endif
