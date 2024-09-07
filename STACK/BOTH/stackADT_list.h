#ifndef STACKADT_LIST_H
#define STACKADT_LIST_H

#include "stackadt.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stackADT_list.h"

// Initialize the stack
void initialize(Stack *S) {
    *S = (Stack) malloc(sizeof(Stacktype));  // Allocate memory for the stack structure

    if (*S != NULL) {
        (*S)->data = NULL;  // Data is not used in the linked list implementation
        (*S)->top = NULL;  // Initialize top as NULL
    }
}

void push(Stack S, char elem) {
    List newNode = (List) malloc(sizeof(Node));

    if (newNode != NULL) {
        newNode->elem = elem;                 // Set the new node's data
        newNode->next = (List)(S->top);       // Link the new node to the current top
        S->top = newNode;                     // Update the top pointer (typecasted to void*)
    }
}

void pop(Stack S) {
    // Check if Stack is EMPTY
    if (empty(S)) {
        printf("\nX\n");  // If empty, print X and return
    } else {
        // Continue popping elements until the stack is empty
        while (!empty(S)) {
            displayStack(S);
            List temp = (List)(S->top);    // Access the top node
            char hold = temp->elem;        // Store the top element
            S->top = temp->next;           // Move the top pointer to the next node
            free(temp);                    // Free the popped node
            printf("Pop: %c\n", hold);           // Print the popped element
        } 
    }
}

void top(Stack S) {
    if (empty(S)) {
        printf("Top: X\n");  
    } else {
        List topNode = (List)(S->top);  // cast S->top to List
        printf("\nTop: %c\n",topNode->elem);
    }
}

bool empty(Stack S) {
    return (S->top == NULL);  
}

void makeNull(Stack S) {
    while (S->top != NULL) {
        List temp = (List)(S->top);  // Get the current top node
        S->top = temp->next;         // Move the top pointer to the next node
        free(temp);                  // Free the old top node
    }
    // Finally, set the top pointer to NULL to indicate the stack is empty
    S->top = NULL;
}

void displayStack(Stack S) {
    List curr;            
    printf("Stack: ");
    // Typecast top to List to traverse the stack
    for(curr  = (List)(S->top); curr != NULL; curr = curr->next){ 
        printf("%c ", curr->elem);
    }
}

#endif
