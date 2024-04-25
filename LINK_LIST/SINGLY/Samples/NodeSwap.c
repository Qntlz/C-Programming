/*  Given a linked list, swap the data of adjacent node

    Sample Test Case:

    Enter size of linked list: 5
    Enter element 1: 1
    Enter element 2: 2
    Enter element 3: 3
    Enter element 4: 4
    Enter element 5: 5
    Original linked list: 1 2 3 4 5
    Updated linked list: 2 1 4 3 5
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
NodePtr populate();
void nodeSwap(NodePtr*);
void display(NodePtr);

int main()
{
    int size;
    NodePtr top = NULL;
    top = populate();
    printf("Original linked list: ");
    display(top);
    printf("\nUpdated linked list: ");
    nodeSwap(&top);
    display(top);

    
    return 0;
}

NodePtr makeNode(int n)
{
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->num = n;
    newNode->next = NULL;

    return newNode;
}

NodePtr populate()
{
    int size,num;
    NodePtr newNode,top = NULL,last = NULL;
    printf("Enter size of linked list: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++)
    {
        printf("Enter element %d: ",i + 1);
        scanf("%d", &num);
        newNode = makeNode(num);
        if(top == NULL) top = newNode;
        else last->next = newNode;
        last = newNode;
    }

    return top;
}

void display(NodePtr top)
{
    while(top != NULL)
    {
        printf("%d ", top->num);
        top = top->next;
    }
}

void nodeSwap(NodePtr *top)
{
    int temp;
    NodePtr curr = *top;
    while(curr->next != NULL)
    {
        //Swapping
        temp = curr->num;
        curr->num = curr->next->num;
        curr->next->num = temp;
        if(curr->next->next != NULL) curr = curr->next->next;
        else break;
    }
}