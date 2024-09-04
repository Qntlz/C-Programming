#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Basic Link list Implementation in Stack
// Stack: "LAST In, FIRST Out"

#define rogueVal -999           // Sentinel Value

// Define link list structure
typedef struct node {
    int data;
    struct node *next;
} Node, *List;

// Define a pointer to a list structure
typedef struct{
    List top;
} Stacktype, *Stack;

void initStack(Stack*);                 // Initialize Stack
void display(Stack);
int empty(Stack);                       // Check if Stack is empty
void push(Stack*, int);                 // ADD item to the Stack
int pop(Stack*);                         // CHECKS if the stack is empty

int main()
{
    Stack S;

    // Initialize Stack
    initStack(&S);

    // Push
    for (int i = 0; i < 5; i++){
        push(&S,i + 1);
    }

    // Display Stack
    display(S);

    // Pop
    printf("\n\nPop:\n");
    while(!empty(S)){
        printf("%d ", pop(&S));
    }

    // Free allocated memory
    free(S);

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
    for(trav = S->top;trav != NULL; trav = trav->next){
        printf("%d ", trav->data);
    }
}

void push(Stack *S, int num)
{
    List newNode = malloc(sizeof(Node));

    if(newNode != NULL){
        newNode->data = num;
        newNode->next = (*S)->top;
    }
    (*S)->top = newNode;
}

int pop(Stack *S)
{
    // Check if Stack is EMPTY
    if(empty(*S)){
        return rogueVal;
    }
    else{
        int hold = (*S)->top->data;  // Store data pointed by top
        List temp = (*S)->top;
        (*S)->top = temp->next;
        free(temp);
        return hold;
    }
}


