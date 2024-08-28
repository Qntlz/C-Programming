#include <stdio.h>
#include <stdlib.h>

// Insert an element at a specific position in the  list

// Define Node Structure
typedef struct node
{
    int data;
    struct node *next;
}Node, *List;

void initList(List*);
void populate(List*);
void display(List);
void insertAtPos(List*, int, int);

int main()
{
    int pos;
    List top;

    // Initialize List
    initList(&top);

    // Populate List
    populate(&top);

    // Display List
    printf("Current List: ");
    display(top);

    // Call insertFirst and insert 7
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    insertAtPos(&top,4,pos);

    // Display List
    printf("After insert: ");
    display(top);

    return 0;
}

void initList(List *top)
{
    // Initialize list to be empty
    *top = NULL;
}
void populate(List *top)
{
    List last = NULL;
    for (int i = 1; i <= 3; i++){
        List newNode = malloc(sizeof(Node));

        // IF memory allocation sucess proceed making the node
        if(newNode != NULL){
            newNode->data = i;
            newNode->next = NULL;
        }

        // IF the list is empty
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
void insertAtPos(List *top, int num, int pos)
{
    int currPos = 0;
    List *trav;

    // Make Node
    List newNode = malloc(sizeof(Node));
    
    // IF memory allocation sucess proceed making the node
    if(newNode != NULL){
        newNode->data = num;
        newNode->next = NULL;
    }

    // Traverse until chosen position
    for (trav = top;*trav != NULL && ++currPos != pos; trav = &(*trav)->next){}

    // If position is found
    if(*trav != NULL){
        newNode->next = *trav;
        *trav = newNode;
    }
}
