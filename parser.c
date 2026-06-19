#include <string.h>
#include "parser.h"

int isSpaceCustom(char c){ //checks if the char has whitespace
  int result = 0;
  if(c == ' ' || c == "\t" || c == '\n' || c == '\r'){
      result = 1;
  }
  return result;
}

int isDigitCustom(char c){
  int result = 0;
  if (c >= '0' && c <= '9'){
      result = 1;
  }
  return result;
}
