#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "parser.h"
#define MAX_INPUT 1024

// Helper function to print the status messages
void printStatus(ErrorStatus status)
{ 
    printf("Status: ");
    switch (status)
    {
        case ERR_NONE: printf("Success\n"); break;
        case ERR_MISMATCH_PAREN: printf("Mismatched Parenthesis\n"); break;
        case ERR_INVALID_CHAR: printf("Invalid Character\n"); break;
        case ERR_MALFORMED: printf("Malformed expression\n"); break;
        case ERR_DIV_ZERO: printf("Division by zero\n"); break;
        default: printf("Error Unknown\n"); break;
    }
}


// Function that evaluates and times the arithmetic execution
void evaluateExpression(const char *expression) 
{
    Queue infixQueue = CreateQueue();
    Queue postfixQueue = CreateQueue();
    int finalResult = 0;
    
    printf("Evaluating Expression: %s\n", expression); // Initializes the queues needed for the pipeline

    clock_t start_time = clock(); // Starts the timer

    ErrorStatus currentStatus = tokenize(expression, &infixQueue);
    
    if (currentStatus == ERR_NONE) {
        currentStatus = infixToPostfix(&infixQueue, &postfixQueue);
    }
    
    if (currentStatus == ERR_NONE) {
        currentStatus = evaluatePostfix(&postfixQueue, &finalResult);  // Runs the 3-Phase Pipeline
    }

    clock_t end_time = clock(); // Stops the timer
    double time_taken = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0; // Stops the timer
    
    if (currentStatus == ERR_NONE) {
        printf("Result: %d\n", finalResult);
    } else {
        printStatus(currentStatus);
    }
    
    printf("Execution Time: %f ms\n", time_taken); // Prints the output time in milliseconds
}


// Function that reads the test_cases.txt file
void runFile(const char *filename) 
{
    // Open file in read mode
    FILE* file = fopen(filename, "r");
    
    // If the file does not exist
    if (file == NULL) 
    {
        printf("\nError: Could not find '%s'.\n", filename);
    } 
    
    // If the file exists
    else 
    {
        char line[MAX_INPUT]; // Buffer for reading the lines in test_cases.txt
        int testCount = 1;  
        
        printf("\n\n======= Generated Test Cases (test_cases.txt) =======\n");
        
        // Read each line until the EOF
        int lineSize = sizeof(line); 
        while (fgets(line, lineSize, file) != NULL) 
        {
            // Remove the newline characters from the end of the line
            line[strcspn(line, "\r\n")] = 0; 
            
            // If the line is not empty
            if (strlen(line) > 0) 
            { 
                printf("\n\nTest Case #%d:\n", testCount);
                evaluateExpression(line);  
                testCount++; 
            }
        }
        
        fclose(file);
    }
}


// Main Function
int main() 
{
    char inputBuffer[MAX_INPUT]; // Holds the user's input; Can be adjusted as needed
    int choice = 0;
    int isActive = 1; 
    
    printf("\n===== CCDSALG MCO1: Arithmetic Evaluator =====");
    
    // Main menu
    do 
    {
        printf("\n1. Input Expression\n");
        printf("2. Run \"test_cases.txt\"\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        
        // If user input is a valid number 
        if (scanf("%d", &choice) == 1) 
        {
            // Clear input buffer
            int c = getchar();
            while (c != '\n' && c != EOF) 
            { 
                c = getchar(); 
            } 
            
            // Choice 1: User input expression
            if (choice == 1) 
            {
                printf("\nEnter expression: ");

                // If user input is valid 
                if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL) 
                {
                    inputBuffer[strcspn(inputBuffer, "\r\n")] = 0; // Remove newline characters
                    printf("\n");
                    evaluateExpression(inputBuffer);
                }
            } 

            // Choice 2: Run test_cases.txt
            else if (choice == 2) 
            {
                runFile("test_cases.txt");
            } 

            // Choice 3: Exit
            else if (choice == 3) 
            {
                printf("\nExiting...Goodbye!\n");
                isActive = 0; 
            } 

            // If invalid input
            else 
            {
                printf("\nERROR: Invalid choice!\n");
            }
        } 

        // If user input is not a valid number
        else 
        {
            printf("\nERROR: Invalid input!\n");
            
            // Clear input buffer
            int c = getchar();
            while (c != '\n' && c != EOF) 
            { 
                c = getchar(); 
            }
        }
        
    } while (isActive == 1);
    
    return 0; 
}
