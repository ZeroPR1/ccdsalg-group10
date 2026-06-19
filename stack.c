#include "stack.h"

// Function that creates an empty Stack
Stack CreateStack() 
{
    Stack S;  // Create a new Stack
    S.top = -1; // Initialize the top index to -1 to indicate that the Stack is empty
    
    return S;
}

// Function that checks if the Stack is empty
int isEmptyStack(Stack *S) 
{
    // Initialize isEmpty to 0 (False)
    int isEmpty = 0;

    // If the top index is -1 (Stack is empty)
    if (S->top == -1) 
    {
        isEmpty = 1; // Set isEmpty to 1 (True)
    }

    return isEmpty;
}

// Function that checks if the Stack is full
int isFullStack(Stack *S) 
{
    // Initialize isFull to 0 (False)
    int isFull = 0;
    
    // If the top index is equal to MAX_TOKENS -1 (Stack is full)
    if (S->top == MAX_TOKENS - 1) 
    {
        isFull = 1; // Set isFull to 1 (True)
    }

    return isFull;
}

// Function that pushes a Token into the Stack
void Push(Stack *S, Token x) 
{
    // If the Stack is not full
    if (!isFullStack(S)) 
    {
        S->top++; // Increment the top index to point to the new top position
        S->array[S->top] = x; // Add the new Token to the top of the Stack
    }
}

// Function that pops a Token from the Stack
Token Pop(Stack *S) 
{
    // Initialize Token to be returned if the Stack is empty
    Token poppedToken = {TOKEN_OPERAND, 0, '\0'}; 

    // If the Stack is not empty
    if (!isEmptyStack(S)) 
    {
        poppedToken = S->array[S->top]; // Get the top Token
        S->top--; // Decrement the top index to remove the top Token from the Stack
    }

    return poppedToken;
}

// Function that returns the top Token of the Stack
Token Top(Stack *S) 
{
    // Initialize Token to be returned if the Stack is empty
    Token getTop = {TOKEN_OPERAND, 0, '\0'}; 

    // If the Stack is not empty
    if (!isEmptyStack(S)) 
    {
        getTop = S->array[S->top]; // Get the top Token
    }

    return getTop;
}
