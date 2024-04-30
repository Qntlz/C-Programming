/*
Given two linked lists representing numbers in reverse order, add them and return the result as a linked list.
Sample Test case:

    Enter size of first linked list: 2
    Enter element 1: 1
    Enter element 2: 2
    Enter size of second linked list: 3
    Enter element 1: 4
    Enter element 2: 5
    Enter element 3: 6
    First linked list: 1 2
    Second linked list: 4 5 6
    Sum: 5 7 6

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
void populate(NodePtr*,NodePtr*);
void display(NodePtr);
void getSum(NodePtr,NodePtr);

int main()
{
    NodePtr firList = NULL, secList = NULL;
    populate(&firList,&secList);
    printf("First linked list: ");
    display(firList);
    printf("Second linked list: ");
    display(secList);
    getSum(firList,secList);
    return 0;
}

NodePtr makeNode(int num)
{
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->num = num;
    newNode->next = NULL;
    return newNode;
}
void populate(NodePtr *fir, NodePtr *sec)
{
    int size,num;
    NodePtr last  = NULL, newNode = NULL;
    printf("Enter size of first linked list: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d", &num);
        newNode = makeNode(num);
        if(*fir == NULL) *fir  = newNode;
        else last->next = newNode;
        last = newNode;
    }

    last = NULL, newNode = NULL;
    printf("Enter size of second linked list: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d", &num);
        newNode = makeNode(num);
        if(*sec == NULL) *sec  = newNode;
        else last->next = newNode;
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
    printf("\n");
}

void getSum(NodePtr fir, NodePtr sec)
{
    printf("Sum: ");
    while (fir != NULL || sec != NULL)
    {
        int sum = 0;
        if (fir != NULL)
        {
            sum += fir->num;
            fir = fir->next;
        }
        if (sec != NULL)
        {
            sum += sec->num;
            sec = sec->next;
        }
        printf("%d ", sum);
    }
    printf("\n");
}
