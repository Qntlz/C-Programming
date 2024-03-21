#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
void printList(NodePtr);
void insertNode(NodePtr,NodePtr*,NodePtr*);

int main()
{
    int n, size;
    NodePtr top = NULL, last = NULL, np;
    printf("Enter amount nodes: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter value of Node %d: ", i + 1);
        scanf("%d", &n);
        np = makeNode(n);
        insertNode(np,&top,&last);
        // if (top == NULL) top = np;
        // else last->next = np;
        // last = np;
    }
    printList(top);

    return 0;
}

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
}
void insertNode(NodePtr np,NodePtr *top,NodePtr *last)
{
    if (*top == NULL) *top = np;
    else (*last)->next = np;
    *last = np;
}

void printList(NodePtr np)
{
    int ctr = 1;
    printf("Data: \n");
    while (np != NULL)
    {
        printf("Node %d: %d\n", ctr, np->num);
        np = np->next;
        ctr++;
    }
}