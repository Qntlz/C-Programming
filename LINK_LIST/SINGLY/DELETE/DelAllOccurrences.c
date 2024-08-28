#include <stdio.h>
#include <stdlib.h>

// Deleting a Node Using PPTN
// Task: Delete the all occurence of the target integer 

typedef struct node
{
    int data;
    struct node *next;
}Node, *List;

List makeNode(int);
void initList(List*);
void populate(List*);
void display(List);
void delAllOcc(List*,int);

int main()
{
    int target = 10;                    // Target Value to be deleted
    List head;

    initList(&head);
    populate(&head);

    printf("Target Integer to Delete: %d\n",target);

    printf("Before Deletion: ");        // Before Deleting a Node
    display(head);
    printf("\n");

    delAllOcc(&head,target);
    printf("After Deletion: ");        // Before Deleting a Node
    display(head);

    return 0;
}

List makeNode(int num)
{
    // Dynamically Allocate Memory for Node
    List newNode = malloc(sizeof(Node));

    // IF memory allocation sucess proceed making the node
    if(newNode == NULL) {
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
    // Dummy Values
    int arr[] = {10,10,15,10};

    List last = NULL;
    for (int i = 0; i < 4; i++){
        List newNode = makeNode(arr[i]);
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

void delAllOcc(List *head,int target)
{
    List *trav;

    for (trav = head; *trav != NULL;)
    {
        if((*trav)->data == target){
            List temp = *trav;
            *trav = temp->next;
            free(temp);
        }
        else{
            trav = &(*trav)->next;
        }
    }
    
    
    
}