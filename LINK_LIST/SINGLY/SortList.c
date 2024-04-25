/* Write a program to sort a linked list in ascending order.
   In using Merge Sort for this program,
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

NodePtr SortedMerge(NodePtr,NodePtr);
void split(NodePtr,NodePtr*,NodePtr*);
void MergeSort(NodePtr*);               // Sorts the linked list by changing next pointers (not data)

void display(NodePtr);

int main()
{
    NodePtr top = NULL;
    top = populate();
    
    // Before Sorting
    printf("Original linked list: ");
    display(top);

    // After Sorting
    MergeSort(&top);
    printf("\nSorted linked list: ");
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
    int num;
    NodePtr top = NULL, last = NULL,newNode = NULL;

    while (num != 0)
    {
        printf("Enter element (enter 0 to stop): ");
        if(scanf("%d", &num) == 0 || num == 0) break;
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
        printf("%d ",top->num);
        top = top->next;
    }
}
void MergeSort(NodePtr *top)
{
    NodePtr a = NULL,b = NULL,curr = *top;

    // Base Case
    if((curr == NULL) || curr->next == NULL) return;

    // Split head into 'a' & 'b' sublist
    split(curr,&a,&b);

    // Recursively sort the sublists
    MergeSort(&a);
    MergeSort(&b);

    *top = SortedMerge(a,b);
}
void split(NodePtr curr,NodePtr *front,NodePtr *back)
{
    NodePtr slow = curr, fast = curr->next;

    while (fast != NULL)
    {
        fast = fast->next;      // Advance fast in two nodes
        if(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;      // Advance slow in one node
        }
    }
    
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *front = curr;
    *back = slow->next;
    slow->next = NULL;

}
NodePtr SortedMerge(NodePtr a,NodePtr b)
{
    NodePtr result = NULL;

    // Base Cases
    if(a == NULL) return b;
    else if(b == NULL) return a;

    if(a->num <= b->num)
    {
        result = a;
        result->next = SortedMerge(a->next,b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a,b->next);
    }
    return result;
}