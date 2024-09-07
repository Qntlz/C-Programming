#ifndef STACK_H
#define STACK_H

#define MAX 10
#define rogueVal -999          // Sentinel Value

#include <stdbool.h> 

// Stack type definition
typedef struct {
    void *data;  // Pointer to stack data (could be array or linked list)
    void *top;   // Pointer to top index (for array) or top node (for linked list)
} Stacktype, *Stack;

// Define link list structure
typedef struct node {
    char elem;
    struct node *next;
} Node, *List;

// Function declarations
void initialize(Stack*);
void push(Stack, char);
void pop(Stack);
void top(Stack);
bool empty(Stack);
bool full(Stack);
void makeNull(Stack);
void displayStack(Stack);

#endif
