#include <stdio.h>
#include <stdlib.h>

// Array Implementation in Link List (Delete First Occurrence using Last Index)

#define MAX 10

typedef struct node {
    int arr[10];
    int lastIdx;            // Stores the index of the last element in the array
} Node, *List;

void initList(List*);
void populate(List*);
void display(List);
void delFirstOccurIdx(List, int);

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
    printf("Last Index: %d\nTarget to Delete: %d\n",head->lastIdx,target);

    delFirstOccurIdx(head,target);

    printf("After Deleting the first Occurence: ");
    display(head);
    printf("Last Index: %d",head->lastIdx);

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

    int temp = 1;                   // Dummy element to store
    (*head)->lastIdx = -1;          // Initialize last index to -1
    for(int i = 0; i < 6; i++){
        (*head)->arr[++(*head)->lastIdx] = temp;
        if(i % 2 != 0){
            temp++;
        }
    }
}

void display(List head)
{
    for(int i = 0; i <= head->lastIdx; i++){
        printf("%d",head->arr[i]);
    }
    printf("\n");
}

void delFirstOccurIdx(List head, int num)
{
    // Traverse
    int i;
    for (i = 0; i <= head->lastIdx && head->arr[i] != num; i++){};

    // If FOUND
    if(i <= head->lastIdx){
        //Shift elements
        for (int j = i; j < head->lastIdx; j++){
            head->arr[j] = head->arr[j + 1];
        }
        head->lastIdx--;
    }
}