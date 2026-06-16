#include <stdlib.h>
#include "collections.h"

//Stack Operations
void initStack(Stack* s, int cap){
  s->top = -1;
}

void push(Stack* s, Token t){
  if (s->top < MaxCapacity - 1){
    s->top = s->top + 1;
    s->data[s->top] = t;
  }
}

Token pop(Stack* s){
  Token t;
  t.type = TOKEN_INVALID;
  if (s->top >= 0){
      t =  s->data[s->top];
      s->top =  s->top - 1;
  }
  return t;
}

Token peekStack(Stack* s){
    Token t;
    t.type = TOKEN_INVALID;
    if (s->top >=0){
        t = s->data[s->top];
    }
    return t;
}

int isStackEmpty(Stack* s){
    int empty = 0;
    if (s->top == -1) {
        empty = 1;
    }
    return empty;
}

void initQueue(Queue* q){
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(Queue* q, Token t){
    if(q->size < MaxCapacity){
      q->rear = (q->rear + 1) % MaxCapacity;
      q->data[q->rear] = t;
      q->size = q->size + 1;
    }
}

Token dequeue(Queue* q){
  Token t;
  t.type = TOKEN_INVALID;
  if (q->size > 0){
      t = q->data[q->front];
      q->front = (q->front + 1) % MaxCapacity;
      q->size = q->size - 1;
  }
  return t;
}

int isQueueEmpty(Queue *q){
  int empty = 0;
  if (q->size == 0){
      empty = 1;
  }
  return empty;
}
