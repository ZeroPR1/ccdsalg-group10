#pragma once
#define MaxCapacity 10500
#include "types.h"


typedef struct {
  Token* data[MaxCapacity];
  int top;
} Stack;

typedef struct {
  Token* data[MaxCapacity];
  int front;
  int rear;
  int size;
} Queue;

//Stack Prototypes
void initStack(Stack* s, int cap);
void push(Stack* s, Token t);
Token pop(Stack* s);
Token peekStack(Stack* s);
int isStackEmpty(Stack* s);

//Queue Prototypes
void initQueue(Queue* q, int cap);
void enqueue(Queue* q, Token T);
Token dequeue(Queue* q);
int isQueueEmpty(Queue* q);
