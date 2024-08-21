#include <stdio.h>
#include <stdlib.h>

// Deleting a Node Using PPTN
// Task: Delete the first occurence of the target integer 

typedef struct node
{
    int data;
    struct node *next;
}Node, *List;

List makeNode(int);
void populate(List*);
void display(List);
void delNode(List*,int);

int main()
{
    int target = 20;                    // Target Value to be deleted
    List head = NULL;

    populate(&head);

    printf("Before Deletion: ");        // Before Deleting a Node
    display(head);
    printf("\n");

    delNode(&head,target);
    printf("After Deletion: ");        // Before Deleting a Node
    display(head);

    return 0;
}

List makeNode(int num)
{
    List newNode = malloc(sizeof(Node));

    if(newNode == NULL) {
        printf("Memory Allocation Failed");
    }

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

void delNode(List *head,int target)
{
    List *trav = head;
    
    // Traverse the list
    for (;*trav != NULL; trav = &(*trav)->next){
        // If target was found
        if((*trav)->data == target){
            List temp = *trav;
            *trav = temp->next;
            free(temp);
            return;
        }
    }
}