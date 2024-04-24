/*
    Write a program to count the number of nodes in a linked list. 
    Ask input for elements that will stop once 0 is inputted.
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
int countNode(NodePtr);

int main()
{
    int numNodes = 0;
    NodePtr top = NULL;
    top = populate();
    numNodes = countNode(top);
    printf("Number of nodes: %d",numNodes);
    return 0;
}

NodePtr makeNode(int num)
{
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}
NodePtr populate()
{
    int num;
    NodePtr top = NULL, last = NULL,newNode = NULL;

    while (num != 0)
    {
        printf("Enter element (enter 0 to stop): ");
        if(scanf("%d", &num) == 0 || num == 0) break;
        newNode = makeNode(num);
        if(top == NULL) top = newNode;
        else last->next = newNode;
        last = newNode;
    }
    return top;
}
int countNode(NodePtr top)
{
    int ctr = 0;
    while (top != NULL)
    {
        ctr++;
        top = top->next;
    }
    return ctr;
}