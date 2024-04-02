#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void populateArr(int*, int);
void displayArr(int*, int);
int* insert(int*, int*, int, int);
void search(int*,int,int);
void sort(int*,int);

int main()
{
    int size,key;
    printf("Enter array size: ");
    scanf("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));

    populateArr(arr, size);
    printf("Original: ");
    displayArr(arr, size);

    arr = insert(arr, &size, 10, 1);
    printf("\nAfter Insert: ");
    displayArr(arr, size);

    printf("\nEnter Value to Search: ");
    scanf("%d", &key);
    search(arr,size,key);

    printf("\nBefore Sort: ");
    displayArr(arr,size);
    sort(arr,size);
    printf("\nAfter Sort: ");
    displayArr(arr,size);

    return 0;
}

void populateArr(int* arr, int size)
{
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
}

void displayArr(int* arr, int size)
{
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
}   


int* insert(int* arr, int* size, int value, int pos)
{
    (*size)++;
    arr = realloc(arr, *size * sizeof(int));

    for (int i = *size - 1; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    return arr;
}

void search(int *arr,int size,int key)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == key)
        {
            printf("%d is at index %d",key,i);
            return;
        }
    }
    printf("%d not Found!\n",key);
    return;
}

void sort(int *arr,int size)
{
    int key,j;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];       
        j = i - 1;            

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
}

