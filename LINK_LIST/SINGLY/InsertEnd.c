#include <stdio.h>
#include <stdlib.h>

// Define Node Structure
typedef struct node {
    int data;
    struct node *next;
} Node, *List;

List makeNode(int);
void populate(List*,List*);
void display(List);
void insertEnd(List*,int);

int main()
{
    int num;
    List head = NULL, last = NULL;

    populate(&head, &last);
    display(head);

    // Demo for inserting end
    printf("Enter number to insert: ");
    scanf("%d", &num);

    insertEnd(&head,num);

    // Display inserted element
    display(head);

    return 0;
}

List makeNode(int n)
{
    List newNode = (List)malloc(sizeof(Node));      // Dynamically Allocate Memory for Node

    if(newNode == NULL) {
        printf("Memory Allocation Failed");
    }

    newNode->data = n;
    newNode->next = NULL;
    return newNode;
}

void populate(List *head, List *last)
{
   for (int i = 1; i <= 3; i++)
   {
        List newNode = makeNode(i);
        if(*head == NULL)   // If the list is empty
        {
            *head = newNode;
            *last = newNode;
        }

        (*last)->next = newNode;
        *last = newNode;
   }
}

void display(List head)
{
    List trav = head;
    while(trav != NULL)
    {
        printf("%d",trav->data);
        trav = trav->next;
    }
    printf("\n");
}

void insertEnd(List *head,int target)
{
    List *trav;

    // Traverse the list
    for (trav = head; *trav != NULL && (*trav)->data != target; trav = &(*trav)->next);
    
    // If the element is present exit 
    if(*trav != NULL) {
        printf("Element Already existed!");
        return;
    }

    // If the element was not found
    *trav = makeNode(target);            // What is wrong in this part?
    
}