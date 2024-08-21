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
void populate(List *);
void display(List);
void insertSorted(List *, int);

int main()
{
    int num;
    char opt;
    List head = NULL;

    populate(&head);
    printf("Before Insert: ");
    display(head);

    // Demo for inserting sorted list
    do
    {
    
        printf("Enter number to insert: ");
        scanf("%d", &num);

        insertSorted(&head,num);

        // Display sorted list
        printf("New Sorted List: ");
        display(head);

        printf("Enter another element? [Y/N]: ");
        scanf(" %c", &opt);

    } while (opt != 'N');

    return 0;
}

List makeNode(int num)
{
    List newNode = (List)malloc(sizeof(Node)); // Dynamically Allocate Memory for Node

    if (newNode == NULL){
        printf("Memory Allocation Failed"); // Error Checking
    }

    newNode->data = num;
    newNode->next = NULL;
    return newNode;
}

void populate(List *head)
{
    List last = NULL;
    for (int i = 1; i <= 3; i++){
        List newNode = makeNode(i);
        if (*head == NULL){
            *head = newNode;
            last = newNode;
        }

        last->next = newNode;
        last = newNode;
    }
}

void display(List head)
{
    for (; head != NULL; head = head->next){
        printf("%d ", head->data);
    }
    printf("\n");
}

void insertSorted(List *head, int num)
{
    List *curr;
    List newNode = makeNode(num);

    for (curr = head; *curr != NULL && (*curr)->data < num; curr = &(*curr)->next){}

    if (*curr != NULL){
        newNode->next = *curr;
        *curr = newNode;
    }
    else {
        *curr = newNode;
    }
}
