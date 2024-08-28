#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Insert at the END using Pointer to Pointer to Node (PPTN) Method if the element
// is NOT PRESENT in the list

// Define Node Structure
typedef struct node
{
    int data;
    struct node *next;
} Node, *List;

List makeNode(int);
void populate(List*);
void display(List);
bool insertEndUnique(List*, int);


int main()
{
    int num;
    List head = NULL;

    populate(&head);
    printf("Before Insert: ");
    display(head);

    // Demo for inserting end
    printf("Enter number to insert: ");
    scanf("%d", &num);

    bool result = insertEndUnique(&head,num);         // Insert at the end using traversal

    // Display inserted element
    printf("\nAfter Insert: \n");
    (result) ? printf("Successfully Added!\n") : printf("Element Already exist!\n");
    display(head);

    return 0;
}

List makeNode(int num)
{
    List newNode = (List)malloc(sizeof(Node)); // Dynamically Allocate Memory for Node

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

void populate(List *head)
{
    List last = NULL;
    for (int i = 1; i <= 3; i++){
        List newNode = makeNode(i);
        if (*head == NULL) {
            *head = newNode;
            last = newNode;
        }

        last->next = newNode;
        last = newNode;
    }
}

void display(List head)
{
    for (; head != NULL; head = head->next) {
        printf("%d ",head->data);
    }
    printf("\n");
}

bool insertEndUnique(List *head, int target)
{
    List *trav;

    // Traverse the list using PPTN Method
    for (trav = head; *trav != NULL && (*trav)->data != target; trav = &(*trav)->next){}

    // If the element is present exit
    if (*trav != NULL){
        return false;
    }

    // If the element was not found proceed inserting at the last
    *trav = makeNode(target);
    return true;
}
