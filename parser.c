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

ErrorStatus tokenize(const char* input,  Queue* outputQueue){
    ErrorStatus status = ERR_NONE; //start of with no errors
    int i = 0; //intializes the index counter to 0
    int len = strlen(input); //calculate the total number of characters
    int keepGoing = 1; //assigned variable to control the main loop

    
    
}
