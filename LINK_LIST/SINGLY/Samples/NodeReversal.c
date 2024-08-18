// Write a program to reverse a linked list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
NodePtr populate();
void display(NodePtr);
NodePtr revList(NodePtr);

int main()
{
    NodePtr top = NULL;
    top = populate();

    //Before reverse
    printf("Linked list before reversal: ");
    display(top);

    //After reverse
    top =  revList(top);
    printf("Linked list after reversal: ");
    display(top);

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
    int num,size;
    NodePtr top = NULL, last = NULL, newNode = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
    {
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
    while (top != NULL)
    {
        printf("%d ", top->num);
        top = top->next;
    }
    printf("\n");
} 
NodePtr revList(NodePtr top)
{
    NodePtr curr = top,next = NULL,prev = NULL;


    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
