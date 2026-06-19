#ifndef QUEUE_H
#define QUEUE_H

#include "token.h"

// Queue Structure
typedef struct 
{
    int head; // Index of the first element in the Queue
    int tail; // Index of the last element in the Queue
    int size; // Number of elements in the Queue
    Token array[MAX_TOKENS]; // Array to hold the tokens in the Queue
} Queue;

// Queue Function Prototypes
Queue CreateQueue();
void Enqueue(Queue *Q, Token x);
Token Dequeue(Queue *Q);
Token Head(Queue *Q);
Token Tail(Queue *Q);
int isEmptyQueue(Queue *Q);
int isFullQueue(Queue *Q);

#endif
