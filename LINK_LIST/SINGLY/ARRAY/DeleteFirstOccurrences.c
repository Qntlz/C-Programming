#include <stdio.h>
#include <stdlib.h>

// Array Implementation in Link List (Delete First Occurrence using Count)

#define MAX 10

typedef struct node {
    int arr[10];
    int count;               // Stores the number of elements in the array
} Node, *List;

void initList(List*);
void populate(List*);
void display(List);
void delFirstOccur(List, int);

int main()
{
    int target = 2;             // Target to Delete
    List head;

    // Initialize list
    initList(&head);

    // Populate List
    populate(&head);

    // Display Array Contents & Count
    printf("Current List: ");
    display(head);
    printf("Count: %d\nTarget to Delete: %d\n",head->count,target);

    delFirstOccur(head,target);

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
    // Dynamically Allocate Memory
    *head = malloc(sizeof(Node));

    // Error Checking if Memory Allocation was successful
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

void delFirstOccur(List head, int num)
{
    // Traverse
    int i,limit = head->count - 1;
    for (i = 0; i < head->count && head->arr[i] != num; i++){};

    // If FOUND
    if(i < head->count){
        //Shift elements
        for (int j = i; j < limit; j++){
            head->arr[j] = head->arr[j + 1];
        }
        head->count--;
    }
}