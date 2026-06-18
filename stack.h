#ifndef STACK_H
#define STACK_H

#include "token.h" 

// Stack Structure 
typedef struct 
{
    int top; // Top element index of the Stack
    Token array[MAX_TOKENS]; // Holds the tokens in the Stack
} Stack;

// Stack Function Prototypes
Stack CreateStack();
void Push(Stack *S, Token x);
Token Pop(Stack *S);
Token Top(Stack *S);
int isEmptyStack(Stack *S);
int isFullStack(Stack *S);

#endif
