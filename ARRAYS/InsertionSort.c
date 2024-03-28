/*
    Write a function that takes an array of integers as input and sorts the array in ascending order. 
*/

#include <stdio.h>
#include <stdlib.h>

void sortArr(int*,int);

int main()
{
    int size;
        printf("Enter the number of elements: ");
    scanf("%d", &size);
    int *arr = (int*)malloc(size*sizeof(int));
    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    sortArr(arr,size);
    printf("Sorted array in ascending order:\n");
    for(int i = 0; i < size; i++) printf("%d ",arr[i]);
    return 0;
}

void sortArr(int *arr,int size)
{
    // Insertion Sort Method
    int j,key;
    for(int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

            while(j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        arr[j + 1] = key;
    }
}