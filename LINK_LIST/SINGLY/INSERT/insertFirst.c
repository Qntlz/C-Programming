#include <stdio.h>
#include <stdlib.h>

// Insert an element at the beginning of the link list

// Define Node Structure
typedef struct node
{
    int data;
    struct node *next;
}Node, *List;

void initList(List*);
void populate(List*);
void display(List);
void insertFist(List*, int);

int main()
{
    List top;

    // Initialize List
    initList(&top);

    // Populate List
    populate(&top);

    // Display List
    printf("Current List: ");
    display(top);

    // Call insertFirst and insert 7
    insertFist(&top,7);

    // Display List
    printf("After insert: ");
    display(top);

    return 0;
}

void initList(List *top)
{
    *top = NULL;
}
void populate(List *top)
{
    List last = NULL;
    for (int i = 1; i <= 3; i++){
        List newNode = malloc(sizeof(Node));

        // Error Checking
        if(newNode != NULL){
            newNode->data = i;
            newNode->next = NULL;
        }

        if(*top == NULL){
            *top = newNode;
        }
        else{
            last->next = newNode;
        }
        last = newNode;
    }
    
}
void display(List top)
{
    for (; top != NULL; top = top->next){
        printf("%d ",top->data);
    }
    printf("\n");
}
void insertFist(List *top, int num)
{
    // Make Node
    List newNode = malloc(sizeof(Node));
    if(newNode != NULL){
        newNode->data = num;
        newNode->next = NULL;
    }

    // If list is EMPTY
    if(*top == NULL){
        *top = newNode;
    }
    else{
        newNode->next = *top;
        *top = newNode;
    }
}
