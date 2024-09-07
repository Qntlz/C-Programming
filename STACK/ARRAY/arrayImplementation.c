#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void top(Stack);                            // Displays the top

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
    top(S);
 

    // Pop
    printf("\n\nPop:\n");
    for (int i = S->top; i >= 0; i--){
        printf("%d ",pop(S));
    }
    top(S);

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
    return (S->top == -1);      // Return -1 if the stack is empty
}

void push(Stack S, int n)
{
    // Check if the stack is FULL
    if(S->top != MAX - 1){
        S->arr[++(S->top)] = n;
    } else {
        printf("Stack Overflow: Cannot push %d, stack is full.\n", n);
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

void top(Stack S){
    printf("\nTop: %d\n",S->top);
}
