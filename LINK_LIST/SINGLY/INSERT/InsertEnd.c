#include <stdio.h>
#include <stdlib.h>

// Insert at the END using Pointer to Pointer to Node (PPTN) Method & last pointer

// Define Node Structure
typedef struct node
{
    int data;
    struct node *next;
} Node, *List;

List makeNode(int);
void initList(List*,List*);
void populate(List*, List*);
void display(List);
void insertEnd(List*, int);
void insertEndLastPtr(List, int);      // Inserting End using last pointer

int main()
{
    int num;
    List head,last;      // last pointer stores the address of the last node

    // Initialize List & last pointer
    initList(&head,&last);

    // Populate List
    populate(&head, &last);

    // Display List
    printf("Before Insert: ");
    display(head);

    // Demo for inserting end
    printf("Enter number to insert: ");
    scanf("%d", &num);

    insertEnd(&head,num);         // Insert at the end using traversal
    //insertEndLastPtr(last, num);            // Insert at the end using the last pointer

    // Display inserted element
    printf("After Insert: ");
    display(head);

    return 0;
}

void initList(List *head, List *last)
{
    *head = NULL;
    *last = NULL;
}

List makeNode(int num)
{
    // Dynamically Allocate Memory for Node
    List newNode = (List)malloc(sizeof(Node)); 

    // IF memory allocation sucess proceed making the node
    if (newNode == NULL){
        printf("Memory Allocation Failed"); 
    }
    else{
        newNode->data = num;
        newNode->next = NULL;
    }
    return newNode;
}

void populate(List *head, List *last)
{
    for (int i = 1; i <= 3; i++){
        List newNode = makeNode(i);
        // If the list is empty
        if (*head == NULL) {      
            *head = newNode;
            *last = newNode;
        }

        (*last)->next = newNode;
        *last = newNode;
    }
}

void display(List head)
{
    for (; head != NULL; head = head->next) {
        printf("%d ",head->data);
    }
    printf("\n");
}

void insertEnd(List *head, int target)
{
    List *trav;

    // Traverse the list using PPTN Method
    for (trav = head; *trav != NULL; trav = &(*trav)->next){}

    // Insert at the last
    *trav = makeNode(target);
}

void insertEndLastPtr(List last, int target)
{
    last->next = makeNode(target);
}