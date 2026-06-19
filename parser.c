#include <string.h>
#include "parser.h"

int isSpaceCustom(char c){ //checks if the char has whitespace
  int result = 0;
  if(c == ' ' || c == "\t" || c == '\n' || c == '\r'){
      result = 1;
  }
  return result;
}
