/*  Given two linked lists, concatenate them into a single linked list

    Sample Test Case:

    Enter size of linked list 1: 3
    Enter element 1: 1
    Enter element 2: 2
    Enter element 3: 3
    Enter size of linked list 2: 4
    Enter element 1: 1
    Enter element 2: 2
    Enter element 3: 3
    Enter element 4: 4
    Linked list 1: 1 2 3
    Linked list 2: 1 2 3 4
    Concatenated linked list: 1 2 3 1 2 3 4
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
NodePtr combineList(NodePtr, NodePtr);
void populate(NodePtr *, NodePtr *);
void display(NodePtr);

int main()
{
    NodePtr firList = NULL, secList = NULL, newList = NULL;

    populate(&firList, &secList);
    printf("Linked list 1: ");
    display(firList);
    printf("\nLinked list 2: ");
    display(secList);
    newList = combineList(firList, secList);
    printf("\nConcatenated linked list: ");
    display(newList);

    return 0;
}

NodePtr makeNode(int num)
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));

    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}

void populate(NodePtr *fir, NodePtr *sec)
{
    int num, size;
    NodePtr last = NULL, newNode = NULL;

    printf("Enter size of linked list 1: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &num);
        newNode = makeNode(num);
        if (*fir == NULL)
            *fir = newNode;
        else
            last->next = newNode;
        last = newNode;
    }
    last = NULL;
    newNode = NULL;
    printf("Enter size of linked list 2: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &num);
        newNode = makeNode(num);
        if (*sec == NULL)
            *sec = newNode;
        else
            last->next = newNode;
        last = newNode;
    }
}

void display(NodePtr top)
{
    while (top != NULL)
    {
        printf("%d ", top->num);
        top = top->next;
    }
}

NodePtr combineList(NodePtr fir, NodePtr sec)
{
    NodePtr mergeList = NULL, last = NULL;

    if (fir == NULL) mergeList = sec;
    else
    {
        mergeList = fir;
        last = fir;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = sec;
    }
    return mergeList;
}
