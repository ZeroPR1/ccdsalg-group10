#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include "types.h"

typedef struct {
  Token* data;
  int top;
  int capacity;
} Stack;
