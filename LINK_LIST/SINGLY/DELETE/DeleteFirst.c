#include <stdio.h>
#include <stdlib.h>

// Deleting a Node Using PPTN
// Task: Delete the first node 

typedef struct node
{
    int data;
    struct node *next;
}Node, *List;

List makeNode(int);
void populate(List*);
void display(List);
void delFirNode(List*);

int main()
{
    List head = NULL;

    populate(&head);

    printf("Before Deletion: ");        // Before Deleting a Node
    display(head);
    printf("\n");

    delFirNode(&head);
    printf("After Deletion: ");        // Before Deleting a Node
    display(head);

    return 0;
}

List makeNode(int num)
{
    List newNode = malloc(sizeof(Node));

    if(newNode == NULL) printf("Memory Allocation Failed");

    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

void populate(List *head)
{
    List last = NULL;
    for (int i = 10; i <= 30; i+=10){
        List newNode = makeNode(i);
        if(*head == NULL) *head = newNode;
        else last->next = newNode;
        last = newNode;
    }
}

void display(List head)
{
    for (; head != NULL; head = head->next) {
        printf("%d ",head->data);
    }
}

void delFirNode(List *head)
{
    List temp = *head;                  // Stores the first node in a temporary variable
    *head = temp->next;              // Set the second node to be the first node
    free(temp);                         // Free the old first node
}