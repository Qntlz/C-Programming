#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
void printList(NodePtr,NodePtr,NodePtr,NodePtr,NodePtr);
void insertNode(NodePtr,NodePtr*,NodePtr*);
void categorizeNumber(NodePtr,NodePtr*,NodePtr*,NodePtr*,NodePtr*);

int main()
{
    int n, size;
    NodePtr np, top = NULL, last = NULL, evenTop = NULL,oddTop = NULL,posTop = NULL, negTop = NULL;
    printf("Enter amount nodes: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter value of Node %d: ", i + 1);
        scanf("%d", &n);
        np = makeNode(n);
        insertNode(np, &top, &last);
        // if (top == NULL) top = np;
        // else last->next = np;
        // last = np;
    }
    categorizeNumber(top, &evenTop,&oddTop,&posTop,&negTop);
    printList(top, evenTop,oddTop,posTop,negTop);

    return 0;
}

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr)malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
}
void insertNode(NodePtr np, NodePtr *top, NodePtr *last)
{
    if (*top == NULL) *top = np;
    else (*last)->next = np;
    *last = np;
}

void printList(NodePtr np, NodePtr even, NodePtr odd,NodePtr pos, NodePtr neg)
{
    int ctr = 1;
    printf("\nData: \n");
    while (np != NULL)
    {
        printf("Node %d: %d\n", ctr, np->num);
        np = np->next;
        ctr++;
    }
    ctr = 1;
    printf("\nEven List: \n");
    while (even != NULL)
    {
        printf("Node %d: %d\n", ctr, even->num);
        even = even->next;
        ctr++;
    }
    ctr = 1;
    printf("\nOdd List: \n");
    while (odd != NULL)
    {
        printf("Node %d: %d\n", ctr, odd->num);
        odd = odd->next;
        ctr++;
    }
    ctr = 1;
    printf("\nPositive List: \n");
    while (pos != NULL)
    {
        printf("Node %d: %d\n", ctr, pos->num);
        pos = pos->next;
        ctr++;
    }
        ctr = 1;
    printf("\nNegative List: \n");
    while (neg != NULL)
    {
        printf("Node %d: %d\n", ctr, neg->num);
        neg = neg->next;
        ctr++;
    }
}

void categorizeNumber(NodePtr top,NodePtr *evenTop,NodePtr *oddTop,NodePtr *posTop,NodePtr *negTop)
{
    while (top != NULL)
    {
        NodePtr evenLast,oddLast,posLast,negLast;
        int testNum = top->num;

        if (testNum % 2 == 0)
        {
            NodePtr evenNode = (NodePtr)malloc(sizeof(Node));
            evenNode->num = testNum;
            evenNode->next = NULL;
            if(*evenTop == NULL) *evenTop = evenNode;
            else evenLast->next = evenNode;
            evenLast = evenNode; 
        }
        else
        {
            NodePtr oddNode = (NodePtr)malloc(sizeof(Node));
            oddNode->num = testNum;
            oddNode->next = NULL;
            if(*oddTop == NULL) *oddTop = oddNode;
            else oddLast->next = oddNode;
            oddLast = oddNode; 
        }

        if(testNum >= 0)
        {
            NodePtr posNode = (NodePtr)malloc(sizeof(Node));
            posNode->num = testNum;
            posNode->next = NULL;
            if(*posTop == NULL) *posTop = posNode;
            else posLast->next = posNode;
            posLast = posNode;
        }
        else
        {
            NodePtr negNode = (NodePtr)malloc(sizeof(Node));
            negNode->num = testNum;
            negNode->next = NULL;
            if(*negTop == NULL) *negTop = negNode;
            else negLast->next = negNode;
            negLast = negNode;
        }
        
        top = top->next;
    }
}
