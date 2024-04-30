// Write a program to check if a linked list is a palindrome.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr makeNode(int);
void display(NodePtr);
NodePtr populate();
NodePtr reverseList(NodePtr);
void checkPalindrome(NodePtr);

int main()
{
    NodePtr top = NULL;
    top = populate();
    printf("Original List: ");
    display(top);
    top = reverseList(top);
    printf("\nReverse List: ");
    display(top);
    checkPalindrome(top);

    
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
    int size,num;
    NodePtr top = NULL, last = NULL, newNode = NULL;
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i+1);
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
    while(top != NULL)
    {
        printf("%d ", top->num);
        top = top->next;
    }
}

NodePtr reverseList(NodePtr top)
{
   NodePtr prev = NULL, curr = top,next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void checkPalindrome(NodePtr top)
{
    bool result = true;
    NodePtr slow = top, fast = top,prev_slow = top, half = NULL;

    /*
        fast = skips two nodes
        slow = skips one node
    */

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }
    
    // If Odd number of nodes
    if(fast != NULL) half = slow->next;
    else half = slow;
    prev_slow->next = NULL;         // Terminate the first half

    half = reverseList(half);       // Reverse the second half

    while (top != NULL)
    {
        if (top->num != half->num)
        {
            result = false;
            break;
        }
        top = top->next;
        half = half->next;
    }

    if(result) printf("\nThe linked list is a palindrome.");
    else printf("\nThe linked list is not a palindrome.");
}