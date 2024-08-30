#include <stdio.h>
#include <stdlib.h>

// Array Implementation in Link List (Insert First)
// Change MAX to 4 to apply insert first

#define MAX 3

typedef struct node {
    int arr[MAX];
    int count;               // Stores the number of elements in the array
} Node, *List;

void initList(List*);
void populate(List*);
void display(List);
void insertFirst(List, int);


int main()
{
    int target = 10;             // Target to Insert
    List head;

    // Initialize list
    initList(&head);

    // Populate List
    populate(&head);

    // Display Array Contents & Count
    printf("Current List: ");
    display(head);
    printf("Count: %d\nTarget to Insert: %d\n",head->count,target);

    // Insert First
    insertFirst(head,target);

    printf("After Inserting: ");
    display(head);
    printf("Count: %d",head->count);

    return 0;
}

void initList(List *head)
{
    // Initialize list to be empty
    *head = NULL;
}

void populate(List *head)
{
    // Dynamically Allocate Memory
    *head = malloc(sizeof(Node));

    // Error Checking if Memory Allocation was successful
    if(*head == NULL){
        printf("Memory Allocation Failed\n");
    }

    int dummy[] = {1,2,3};          // Dummy Values
    (*head)->count = 0;
    for(int i = 0; i < 3; i++){
        (*head)->arr[(*head)->count++] = dummy[i];
    }
}

void display(List head)
{
    for(int i = 0; i < head->count; i++){
        printf("%d ",head->arr[i]);
    }
    printf("\n");
}

void insertFirst(List head, int target)
{
    // Check if array is not full
    int ctr = head->count;
    if (ctr < MAX){
        // Shift elements
        for (int i = ctr; i > 0; i--){
            head->arr[i] = head->arr[i - 1];
        } 

        // Insert Element & Increment Count
        head->arr[0] = target;
        head->count++;
    }
}
