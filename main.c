#include <stdio.h>
#include <time.h>
#include "parser.h"

void printError(ErrorStatus status){
    printf("Status: ");
    switch (status){
        case ERR_NONE: printf("Success\n");
        case ERR_MISMATCH_PAREN
    }
}