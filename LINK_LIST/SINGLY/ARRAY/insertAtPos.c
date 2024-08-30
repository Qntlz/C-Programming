#include <stdio.h>
#include <stdlib.h>

// Array Implementation in Link List (Insert At Given Position)
// Assuming index 0 is Positon 1

#define MAX 10

typedef struct node {
    int arr[MAX];
    int count;               // Stores the number of elements in the array
} Node, *List;

void initList(List*);
void populate(List*);
void display(List);
void insertAtPos(List, int, int);


int main()
{
    int target = 10;             // Target to Insert
    int pos = 3;                 // Position to Insert
    List head;

    // Initialize list
    initList(&head);

    // Populate List
    populate(&head);

    // Display Array Contents & Count
    printf("Current List: ");
    display(head);
    printf("Count: %d\nTarget to Insert: %d\n",head->count,target);

    // Insert At Given Position
    insertAtPos(head,target,pos);

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

void insertAtPos(List head, int target, int pos)
{
    // Assuming index 0 is Positon 1
    int ctr = head->count;
    int newPos = pos - 1;

    // Check if the position is within the range and the number of elements
    if((ctr < MAX) && (pos >= 0 && pos < MAX)){
        //Shift elements
        for (int i = ctr; i > newPos; i--){
            head->arr[i] = head->arr[i - 1];
        }
        // Insert element && Increment Count
        head->arr[newPos] = target;
        head->count++;

    }
}
