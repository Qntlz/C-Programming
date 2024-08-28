#include <stdio.h>
#include <stdlib.h>

// Array Implementation in Link List (Delete All Occurrences)

#define MAX 10

typedef struct node {
    int arr[10];
    int count;                  // Stores the number of elements in the array
} Node, *List;

void initList(List*);
void populate(List*);
void display(List);
void delAllOcc(List, int);

int main()
{
    int target = 2;             // Target to Delete
    List head;

    // Initialize List
    initList(&head);

    // Populate List
    populate(&head);

    // Display Array Contents & Count
    printf("Current List: ");
    display(head);
    printf("Count: %d\nTarget to Delete: %d\n",head->count,target);

    delAllOcc(head,target);

    printf("After Deleting All Occurences: ");
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
    *head = malloc(sizeof(Node));

    if(*head == NULL){
        printf("Memory Allocation Failed\n");
    }

    int temp = 1;       // Dummy element to store
    (*head)->count = 0;
    for(int i = 0; i < 6; i++){
        (*head)->arr[(*head)->count++] = temp;
        if(i % 2 != 0){
            temp++;
        }
    }
}

void display(List head)
{
    for(int i = 0; i < head->count; i++){
        printf("%d",head->arr[i]);
    }
    printf("\n");
}

void delAllOcc(List head, int num)
{
    // It modifies the list in-place by shifting elements to fill the gaps left by the removed elements.

    int writeIdx = 0; // Initialize the write index to 0.
    for (int readIdx = 0; readIdx < head->count; readIdx++){
        if (head->arr[readIdx] != num){
            
            // If the current element is not equal to 'num', copy it to the write index position.
            head->arr[writeIdx++] = head->arr[readIdx];
        }
    }
    // Update the list count to reflect the new number of elements after removal.
    head->count = writeIdx;
}
