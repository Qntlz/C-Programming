#include <stdio.h>
#include <stdlib.h>

// Link list will automatically sort every Node added

typedef struct node{
    int num;
    struct node *next;
} Node, *NodePtr;                       // Define Node structure

NodePtr makeNode(int);                      // Function to create a node
NodePtr populate(NodePtr, int);             // Function to populate the list
void display(NodePtr);                      // Function to display the list

int main() {
    // Write C code here
    int n,size;
    NodePtr top = NULL;        // Initialize variables

    printf("Enter size: ");                 // Enter size of the list
    scanf("%d", &size);
    for(int i = 0; i < size; i++)
    {
        printf("\n");
        scanf("%d", &n);
        top = populate(top,n);
        display(top);
    }
    return 0;
}

NodePtr makeNode(int n)
{
    NodePtr np = (NodePtr) malloc(sizeof(Node));       // Dynamically create a pointer(Node)
    np->num = n;                                       // Store the value of n to the new node
    np->next = NULL;                                    
    return np;                                         // Return the pointe of the new node
}

NodePtr populate(NodePtr top,int n)
{
    NodePtr prev = NULL,curr = top,                     // Initialize variables
    newNode = makeNode(n);                              // Create a new node
    if(top == NULL) top = newNode;                     
    else
    {
        while(curr != NULL && n > curr->num)            // Traverse the list while n > than the value at curr->num
        {
            prev = curr;                                // Update the prev variable to the current node
            curr = curr->next;                          // Update curr to point to the next node
        }
        if(prev == NULL)                                // If prev == NULL, meaning the condition breaks at the start   
        {
            newNode->next = top;                        // Set the previous top to be pointed by the newNode
            top = newNode;                              // Set newNode as the new top
            return top;                               
        }
        prev->next = newNode;                           // Sets the previous node to point to the newNode
        newNode->next = curr;                           // Sets the newNode to point to the current node
    }
    return top;
}

void display(NodePtr top)
{ 
    NodePtr curr = top;
    printf("Current List: ");
    while(curr != NULL)                                 // Traverses the list and displays the value of each node
    {
        printf("%d ", curr->num);
        curr = curr->next;
    }
}