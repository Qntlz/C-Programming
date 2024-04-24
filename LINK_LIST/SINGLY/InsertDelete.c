/*
    Here we will tackle the basics on how to make a SINGLY link list
    and implement the following features:

    1. Inserting at the beginning,end and at a specific position
    2. Deleting at the beginning,end and at a specific position

    Our task for today is to insert & delete an integer at the 
    beginning,end and at a specific position
*/


#include <stdio.h>
#include <stdlib.h>             // Must Include both of this libraries

// Define the values of our "Node"
typedef struct node
{
    int num;                // Store the data (integer)
    struct node *next;      // Pointer to the next node
} Node, *NodePtr;           // *NodePtr is used to create a pointer for this node

NodePtr makeNode(int);                    // Function to create a node
void populate(NodePtr*,NodePtr*);         // Function to populate a node
void display(NodePtr);                    // Funciton to display the contents
void insert(NodePtr*,NodePtr*);            // Function to Insert a Node
void delete(NodePtr*);                     // Function to Delete a Node

int main()
{
    NodePtr top = NULL, last = NULL;     // Initialize our top/head to NULL

    populate(&top,&last);                // Pass down the address of top & last
    display(top);
    
    // After Insert
    insert(&top,&last);                 // Pass down the address of top & last
    printf("\nAfter Insert:\n");
    display(top);

    // After Delete
    delete(&top);                 // Pass down the address of top & last
    printf("\nAfter Delete:\n");
    display(top);

    free(top);
    free(last);

    return 0;
}

NodePtr makeNode(int num)
{
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));   // Dynamicall Allocate Memory for our Node

    newNode->num = num;        // Store the data into the node
    newNode->next = NULL;      // Initialize the pointer to the next node to NULL
    return newNode;            // Return the newly created node
}

void populate(NodePtr *top, NodePtr *last)
{
    // Declare & Initialize Variables
    int num;
    NodePtr newNode = NULL;

    printf("Enter any integer [Enter 0 to Stop]:\n");
    scanf("%d", &num);
    while (num != 0)
    {
        newNode = makeNode(num);              // Create a Node
        if(*top == NULL) *top = newNode;      // If top is NULL assign the new node 
        else (*last)->next = newNode;         // Else, connect the previous node to the new node
        *last = newNode;                      // Update last to the newly created node
        scanf("%d", &num);
    }
}

void display(NodePtr top)
{
    int ctr = 0;
    printf("\nLink List of Integers:\n");
    while (top != NULL)                             // Displays the contents of the list until it encounters NULL (NULL means end of the list)
    {
        printf("Node %d: %d\n",++ctr,top->num);     
        top = top->next;                            // Update top to move to the next node
    }
    
}

void insert(NodePtr *top, NodePtr *last)
{
    // Declare & Initialize Variables
    int pos,num,opt,ctr = 1;
    NodePtr newNode,prev = NULL,curr = NULL;

    printf("\nWhere to Insert:\n1.Beginning\n2.End\n3.Specific Position\n");
    scanf("%d",&opt);

    switch (opt)
    {
    case 1:

        printf("-- Insert at the Beginning --\nEnter integer to be inserted: ");
        scanf("%d",&num);

        newNode = makeNode(num);        // Make Node
        newNode->next = *top;           // Let New node point to the old top
        *top = newNode;                 // Set New node as new top
        break;

    case 2:

        printf("-- Insert at the End --\nEnter integer to be inserted: ");
        scanf("%d",&num);

        newNode = makeNode(num);        // Make Node
        (*last)->next = newNode;        // Let the last node point to the new node
        *last = newNode;                // Set the new node as new last 
        break;

    case 3:

        printf("-- Insert at Position --\nEnter Position: ");
        scanf("%d",&pos);                                       
        printf("Enter integer: ");
        scanf("%d", &num);

        newNode = makeNode(num);            // Make Node
        curr = *top;                        // Create a temporary top variable
        while (curr != NULL)
        {
           if(ctr == pos)                   // If in the position
           {
                prev->next = newNode;       // Let the previous node point to the new node
                newNode->next = curr;       // Let the newNode point to the node at that position
                break;
           }
           ctr++;                           // increment ctr, ctr is used to track positions
           prev = curr;                     // Assign current node to prev
           curr = curr->next;               // Update current to move to the next node
        }
        break;
    default:
        printf("Invald Option");
        break;
    }

}

void delete(NodePtr *top)
{
    // Declare & Initialize Variables
    int pos,opt,ctr = 1;
    NodePtr prev = NULL,curr = NULL;

    printf("\nWhere to Delete:\n1.Beginning\n2.End\n3.Specific Position\n");
    scanf("%d",&opt);

    switch (opt)
    {
    case 1:
        *top = (*top)->next;        // Replace the top with the next node
        break;

    case 2:
        curr = *top;                // Create a temporary top variable
        while(curr->next->next != NULL) curr = curr->next;
        curr->next = NULL;
        break;
    case 3:

        printf("-- Delete at Position --\nEnter Position: ");
        scanf("%d",&pos);                                       

        curr = *top;                        // Create a temporary top variable
        while (curr != NULL)
        {
           if(ctr == pos)                   // If in the position
           {
                prev->next = curr->next;    // Point previous to the node pointed by curr
                break;
           }
           ctr++;                           // increment ctr, ctr is used to track positions
           prev = curr;                     // Assign current node to prev
           curr = curr->next;               // Update current to move to the next node
        }
        break;
    default:
        printf("Invald Option");
        break;
    }

}