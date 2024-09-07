#ifndef STACKADT_ARRAY_H
#define STACKADT_ARRAY_H

#include "stackadt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initialize(Stack *S) {
    *S = (Stack) malloc(sizeof(Stacktype));  // Allocate memory for the stack structure

    if (*S != NULL) {
        (*S)->data = malloc(sizeof(char) * MAX);  // Allocate memory for the array

        if ((*S)->data != NULL) {
            (*S)->top = malloc(sizeof(int));  // Allocate memory for the top pointer (int)
            if ((*S)->top != NULL) {
                *((int*)(*S)->top) = -1;  // Initialize top as -1
            }
        }
    }
}

void push(Stack S, char elem) {
    int *top = (int*)S->top;  // Cast top to int*

    // Check if the stack is FULL
    if (*top != MAX - 1) {
        ((char*)S->data)[++(*top)] = elem;
    }
}

void pop(Stack S) {
    if (empty(S)) {
        printf("\nX\n");  // If the stack is empty, print X and return
    } else {
        // Pop all elements from the stack until it is empty
        while (!empty(S)) {
            int topIndex = *(int*)(S->top);  // Get the current top index
            
            // Display the current stack before popping
            displayStack(S);

            // Print and remove the top element
            printf("Pop: %c\n", ((char*)S->data)[topIndex]);

            // Actually "remove" the element by updating the top index
            *(int*)(S->top) = topIndex - 1;
        }
    }
}


void top(Stack S) {
    int *top = (int*)S->top; 
   (empty(S)) ? printf("\nTop: X\n") : printf("\nTop: %c\n",((char*)S->data)[*top]);
}

bool empty(Stack S) {
    int *top = (int*)S->top; 

    return (*top == -1);
}

bool full(Stack S) {
    int *top = (int*)S->top; 

    return (*top == MAX - 1);
}

void makeNull(Stack S) {
    free(S->data);
    S->data = NULL;

    int *top = (int*)S->top; 
    *top = -1;
}

void displayStack(Stack S) {
    int *top = (int*)S->top; 
    printf("Stack: ");
    for (int i = 0; i <= *top; i++) {
        printf("%c ", ((char*)S->data)[i]);
    }
}

#endif
