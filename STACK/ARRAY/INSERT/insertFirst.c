#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Insert First using Array Implementation in Stack
// Stack: "LAST In, FIRST Out"

#define MAX 10
#define rogueVal -999           // Sentinel Value

typedef struct {
    int top;                    // Contains the index of the item at the top of the stack
    int arr[MAX];
} Stacktype, *Stack;

void initStack(Stack*);
void push(Stack, int);                      // ADD item to the Stack
int pop(Stack);                             // REMOVE item from the Stack
bool empty(Stack);                          // CHECKS if the stack is empty
void insertFirst(Stack, int);               // Use to insert at the first index

int main()
{
    Stack S;

    // Initialize Stack
    initStack(&S);

    // Push
    for (int i = 0; i < 5; i++){
        push(S,i + 1);
    }

    // Display
    printf("After Push:\n");
    for (int i = 0; i <= S->top; i++){
        printf("%d ",S->arr[i]);
    }
    printf("\nTop: %d\n",S->arr[S->top]);

    // Call InsertFirst()
    insertFirst(S,7);

    // Display
    printf("\nAfter Insert:\n");
    for (int i = 0; i <= S->top; i++){
        printf("%d ",S->arr[i]);
    }
    printf("\nTop: %d\n",S->arr[S->top]);

    // Free allocated memory
    free(S);

    return 0;
}

void initStack(Stack *S)
{
    *S = malloc(sizeof(Stacktype));
    
    // Error Checking
    if (*S != NULL){
        (*S)->top = -1;
    }
}

bool empty(Stack S)
{
    return (S->top == -1);      // Return -1 if the list is empty
}

void push(Stack S, int n)
{
    // Check if the stack is FULL
    if(S->top != MAX - 1){
        S->arr[++(S->top)] = n;
    }
}

int pop(Stack S)
{
    // Check if the stack is not empty
    if(empty(S)) {
        return rogueVal;        // return a symbolic constant
    }
    return S->arr[(S->top)--];      // Returns the element at the same time decrements top
}

void insertFirst(Stack S, int n)
{
    // Check if not full
    if(S->top != MAX - 1){
        // Shift elements
        for (int i = S->top + 1; i > 0 ; i--){
            S->arr[i] = S->arr[i - 1];
        }
        // Insert the element && Update Top
        S->arr[0] = n;
        S->top++;
    }
}