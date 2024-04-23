/*
    This program creates a link list and will be termianted when the user inputted 0.
    Then it will display all the data in each nodes and how many nodes are present.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);                                  // Function to create a node
int display(NodePtr);                                   // Function to display the data in each node
void insertNode(NodePtr*,NodePtr*,NodePtr);             // Function to add node at the tail of the list.


int main()
{
    int n,ctr;
    NodePtr top = NULL, last = NULL;

    printf("Enter data[Terminates at 0]: ");
    if(scanf("%d", &n) != 1) n = 0;

    while(n != 0)
    {
        NodePtr newNode = makeNode(n);
        insertNode(&top,&last,newNode);
        if(scanf("%d", &n) != 1) n = 0;
    }
    ctr = display(top);
    printf("\nTotal Nodes: %d",ctr);
    return 0;
}

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
}

void insertNode(NodePtr *top,NodePtr *last, NodePtr newNode)
{
    if(*top == NULL) *top = newNode;
    else (*last)->next = newNode;
    *last = newNode;
}

int display(NodePtr top)
{
    int ctr = 0;
    printf("Data within the Node: ");
    while (top != NULL)
    {
        printf("%d ", top->num);
        top = top->next;
        ctr++;
    }
    return ctr;
}
