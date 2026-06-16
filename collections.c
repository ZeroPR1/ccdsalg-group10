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
