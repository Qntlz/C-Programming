/*
    Write a program to count the number of nodes in a linked list.
    Ask input for elements that will stop once 0 is inputted.

    Made by Lance
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
void populate(NodePtr *);
int countNode(NodePtr);

int main()
{
    int numNodes = 0;
    NodePtr top = NULL;
    populate(&top);
    numNodes = countNode(top);
    printf("Number of nodes: %d", numNodes);
    return 0;
}

NodePtr makeNode(int num)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}
void populate(NodePtr *top)
{
    int num;
    NodePtr last = NULL, newNode = NULL;

    do
    {
        printf("Enter element (enter 0 to stop): ");
        scanf("%d", &num);
        newNode = makeNode(num);
        if (*top == NULL) *top = newNode;
        else last->next = newNode;
        last = newNode;
    }while (num != 0);
}
int countNode(NodePtr top)
{
    int ctr = 0;
    for (;top != NULL; top = top->next) ctr++;
    return ctr;
}