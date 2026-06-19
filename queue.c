#include "queue.h"

// Function that creates an empty Queue
Queue CreateQueue() 
{
    Queue Q; // Create a new Queue
    Q.head = 0; // Initialize the head index to 0
    Q.tail = MAX_TOKENS - 1; // Initialize the tail index to the last index of the array
    Q.size = 0; // Initialize size to 0 (Queue is empty)
    return Q;
}

// Function that checks if the Queue is empty
int isEmptyQueue(Queue *Q) 
{
    // Initialize isEmpty to 0 (False)
    int isEmpty = 0;

    // If the size is 0 (Queue is empty)
    if (Q->size == 0) 
    {
        isEmpty = 1; // Set isEmpty to 1 (True)
    }

    return isEmpty;
}

// Function that checks if the Queue is full
int isFullQueue(Queue *Q)
 {
    // Initialize isFull to 0 (False)
    int isFull = 0;

    // If the size is equal to MAX_TOKENS (Queue is full)
    if (Q->size == MAX_TOKENS) 
    {
        isFull = 1; // Set isFull to 1 (True)
    }

    return isFull;
}

// Function that enqueues a Token into the Queue
void Enqueue(Queue *Q, Token x) 
{
    // If the Queue is not full
    if (!isFullQueue(Q)) 
    {
        Q->tail = (Q->tail + 1) % MAX_TOKENS;  // Increment the tail index 
        Q->array[Q->tail] = x; // Add the new Token to the tail of the Queue
        Q->size++; // Increment the size of the Queue
    }
}

// Function that dequeues a Token from the Queue
Token Dequeue(Queue *Q) 
{
    // Initialize the Token to be returned if the Queue is empty
    Token dequeuedToken = {TOKEN_OPERAND, 0, '\0'}; 

    // If the Queue is not empty
    if (!isEmptyQueue(Q)) 
    {
        Q->head = (Q->head + 1) % MAX_TOKENS; // Increment the head index
        dequeuedToken = Q->array[Q->head]; // Get the Token to be dequeued
        Q->size--; // Decrement the size of the Queue
    }

    return dequeuedToken;
}

// Function that returns the head Token of the Queue
Token Head(Queue *Q)   
{
    // Initialize the Token to be returned if the Queue is empty
    Token headToken = {TOKEN_OPERAND, 0, '\0'}; 

    // If the Queue is not empty
    if (!isEmptyQueue(Q)) 
    {
        headToken = Q->array[Q->head]; // Get the head Token
    }

    return headToken;
}

// Function that returns the tail Token of the Queue
Token Tail(Queue *Q) 
{
    // Initialize the Token to be returned if the Queue is empty
    Token tailToken = {TOKEN_OPERAND, 0, '\0'};

    // If the Queue is not empty
    if (!isEmptyQueue(Q)) 
    {
        tailToken = Q->array[Q->tail]; // Get the tail Token
    }

    return tailToken;
}
