/*
    Write a function that takes an array of integers and an integer value as input, 
    and returns the index of the first occurrence of the integer value in the array. 
    If the value is not present in the array, return -1.
*/

#include <stdio.h>
#include <stdlib.h>

int searchIndex(int*,int,int);

int main()
{
    int size,value,index;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int *arr = (int*)malloc(size*sizeof(int));
    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("Enter the value to search: ");
    scanf("%d", &value);
    index = searchIndex(arr,size,value);
    if(index != -1) printf("Index of first occurrence of value in array: %d", index);
    else printf("Value not found in array");
    return 0;
}

int searchIndex(int *arr,int size, int value)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == value) return i;
    }
    return -1;
}