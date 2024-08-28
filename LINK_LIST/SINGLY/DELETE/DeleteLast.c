#include <stdio.h>
#include <stdlib.h>

// Deleting a Node Using PPTN
// Task: Delete the last node 

typedef struct node
{
    int data;
    struct node *next;
}Node, *List;

List makeNode(int);
void initList(List*);
void populate(List*);
void display(List);
void delLastNode(List);

int main()
{
    List head;

    initList(&head);
    populate(&head);

    printf("Before Deletion: ");        // Before Deleting a Node
    display(head);
    printf("\n");

    delLastNode(head);
    printf("After Deletion: ");        // Before Deleting a Node
    display(head);

    return 0;
}

List makeNode(int num)
{
    // Dynamically Allocate Memory for Node
    List newNode = malloc(sizeof(Node));

    // IF memory allocation sucess proceed making the node
    if(newNode == NULL){
        printf("Memory Allocation Failed");
    }

    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

void initList(List *head)
{
    // Initialize list to be empty
    *head = NULL;
}

void populate(List *head)
{
    List last = NULL;
    for (int i = 10; i <= 30; i+=10)
    {
        List newNode = makeNode(i);
        if(*head == NULL) {
            *head = newNode;
        }
        else { 
            last->next = newNode;
        }
        last = newNode;
    }
}

void display(List head)
{
    for (;head != NULL; head = head->next) {
        printf("%d ",head->data);
    }
}

void delLastNode(List head)
{
    List trav = head, temp = NULL;
    // Traverse the List as long as the node next to the current node doesn't point to NULL
    for (;trav != NULL && trav->next->next != NULL; trav = trav->next){}    
    
    temp = trav->next;      // Store the last node in a temporary variable
    trav->next = NULL;      // Detach the last node from the list
    free(temp);             // Free the memory for the last node
}