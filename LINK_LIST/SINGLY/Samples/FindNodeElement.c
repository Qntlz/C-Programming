/*
    Write a program that asks the user to input the size of list and its elements. 
    Then, ask the user to input an element to search for in the list. The program should 
    output whether the element exists or not.
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
void display(NodePtr);
void findElem(NodePtr);

int main()
{
    NodePtr top = NULL;
    top = populate();
    display(top);
    findElem(top);
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
    
    printf("Enter list size: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++)
    {
        printf("Enter Value for Node %d: ", i+1);
        scanf("%d", &num);
        newNode = makeNode(num);
        if (top == NULL)  top = newNode;
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
void findElem(NodePtr top)
{
    int target;
    printf("Enter element to search: ");
    scanf("%d", &target);

    // Find the target
    while (top != NULL)
    {
        if(top->num == target)
        {
            printf("Element found in the list");
            exit(0);
        }
        top = top->next;
    }
    printf("Element not found in the list");
}