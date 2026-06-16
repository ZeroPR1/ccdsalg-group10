#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include "types.h"

typedef struct {
  Token* data;
  int top;
  int capacity;
} Stack;

typedef struct {
  Token* data;
  int front;
  int rear;
  int size;
  int capacity;
} Queue;

//Stack Prototypes
void initStack(Stack* s, int cap);
void push(Stack* s, Token t);
Token pop(Stack* s);
Token peekStack(Stack* s);
int isStackEmpty(Stack* s);
void freeStack(Stack* s);

//Queue Prototypes
void initQueue(Queue* q, int cap);
void enqueue(Queue* q, Token T);
Token dequeue(Queue* q);
int isQueueEmpty(Queue* q);
void freeQueue(Queue* q);

#endif
