/*
    Here we will tackle the basics on how to make a SINGLY link list
    and implement the following features:

    1. Making a Node & Connecting NOdes
    2. Traversing the Link list & Printing its elemetns

    Our task for today is to create a link list of integers
    inputted by the user.
*/

#include <stdio.h>
#include <stdlib.h>             // Must Include both of this libraries

// Define the values of our "Node"
typedef struct node
{
    int num;                // Store the data (integer)
    struct node *next;      // Pointer to the next node
} Node, *NodePtr;           // *NodePtr is used to create a pointer for this node

NodePtr makeNode(int);      // Function to create a node
void populate(NodePtr*);         // Function to populate a node
void display(NodePtr);      // Funciton to display the contents

int main()
{
    NodePtr top = NULL;     // Initialize our top/head to NULL

    populate(&top);       // Returns the top of the created link list
    display(top);
    free(top);
    return 0;
}

NodePtr makeNode(int num)
{
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));   // Dynamicall Allocate Memory for our Node

    newNode->num = num;        // Store the data into the node
    newNode->next = NULL;      // Initialize the pointer to the next node to NULL
    return newNode;            // Return the newly created node
}

void populate(NodePtr *top)
{
    // Declare & Initialize Variables
    int num;
    NodePtr newNode, last = NULL;

    printf("Enter any integer [Enter 0 to Stop]:\n");
    scanf("%d", &num);
    while (num != 0)
    {
        newNode = makeNode(num);            // Create a Node
        if(*top == NULL) *top = newNode;      // If top is NULL assign the new node 
        else last->next = newNode;          // Else, connect the previous node to the new node
        last = newNode;                     // Update last to the newly created node
        scanf("%d", &num);
    }
}

void display(NodePtr head)
{
    int ctr = 0;
    printf("\nLink List of Integers:\n");
    // Displays the contents of the list until it encounters NULL (NULL means end of the list)
    for (; head != NULL; head = head->next) printf("Node %d: %d\n",++ctr,head->num);
    printf("\n");
}