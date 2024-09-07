#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Basic Linked List Implementation of Stack
// Stack: "LAST In, FIRST Out"

#define rogueVal -999           // Sentinel Value

// Define linked list structure
typedef struct node {
    int data;
    struct node *next;
} Node, *List;

// Define a pointer to a list structure
typedef struct {
    List top;
} Stacktype, *Stack;

void initStack(Stack*);                 // Initialize Stack
void display(Stack);                    // Display Stack
int empty(Stack);                       // Check if Stack is empty
void push(Stack*, int);                 // Add item to the Stack
int pop(Stack*);                        // Remove item from the Stack
void freeStack(Stack*);                 // Free all nodes in the Stack

int main()
{
    Stack S;

    // Initialize Stack
    initStack(&S);

    // Push
    for (int i = 0; i < 5; i++){
        push(&S, i + 1);
    }

    // Display Stack
    printf("After Push:\n");
    display(S);

    // Pop
    printf("\n\nDuring Pop:\n");
    while (!empty(S)){
        printf("\nPop: %d", pop(&S));
        display(S);
    }

    // Free allocated memory for the stack
    freeStack(&S);

    return 0;
}

void initStack(Stack *S)
{
    *S = malloc(sizeof(Stacktype));

    // Error Checking
    if(*S != NULL){
        (*S)->top = NULL;
    }
}

int empty(Stack S)
{
    return (S->top == NULL);
}

void display(Stack S)
{
    List trav;
    printf("\nStack: ");
    for (trav = S->top; trav != NULL; trav = trav->next) {
        printf("%d ", trav->data);
    }
}

void push(Stack *S, int num)
{
    List newNode = malloc(sizeof(Node));

    if(newNode != NULL){
        newNode->data = num;
        newNode->next = (*S)->top;   // Link the new node to the previous top
        (*S)->top = newNode;         // Update top to the new node
    } else {
        printf("Memory allocation failed. Push operation aborted.\n");
    }
}

int pop(Stack *S)
{
    // Check if Stack is EMPTY
    if (empty(*S)){
        return rogueVal;
    }
    else{
        int hold = (*S)->top->data;  // Store data from the top node
        List temp = (*S)->top;       // Temporarily store the current top
        (*S)->top = temp->next;      // Move top to the next node
        free(temp);                  // Free the old top node
        return hold;
    }
}

void freeStack(Stack *S)
{
    List temp;
    while ((*S)->top != NULL) {
        temp = (*S)->top;
        (*S)->top = (*S)->top->next;
        free(temp);  // Free each node
    }
    free(*S);        // Free the stack structure itself
}
