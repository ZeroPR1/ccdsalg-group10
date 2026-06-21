#include <stdio.h>
#include <time.h>
#include "parser.h"

void printError(ErrorStatus status){ //helper function to print the error messages
    printf("Status: ");
    switch (status){
        case ERR_NONE: printf("Success\n"); break;
        case ERR_MISMATCH_PAREN: printf("Mismatched Parenthesis\n"); break;
        case ERR_INVALID_CHAR: printf("Invalid Character\n"); break;
        case ERR_MALFORMED: printf("Malformed expression\n"); break;
        case ERR_DIV_ZERO: printf("Division by zero\n"); break;
        default: printf("Error Unknown\n"); break;
    }
}