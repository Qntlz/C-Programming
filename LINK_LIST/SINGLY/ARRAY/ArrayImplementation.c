#include <stdio.h>
#include <stdlib.h>

// Array Implementation in Link List

#define MAX 10

typedef struct node {
    char elem[10];
    int count;                  // Stores the number of elements in the array
} Node, *List;

void initList(List*);
void populate(List*);
void display(List);

int main()
{
    List head;

    // Initialize list
    initList(&head);

    // Populate List
    populate(&head);

    // Display Array Contents & Count
    printf("Current List: ");
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

    char arr[] = {'a','b','c','d','e'};
    (*head)->count = 0;
    for(int i = 0; i < 5; i++){
        (*head)->elem[(*head)->count++] = arr[i];
    }
}

void display(List head)
{
    for(int i = 0; i < head->count; i++){
        printf("%c ",head->elem[i]);
    }
    printf("\n");
}