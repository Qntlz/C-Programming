/*
    Write a function that takes an array of integers as input and returns the array in reverse order.
*/

#include <stdio.h>
#include <stdlib.h>

void reverseArr(int*,int);

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int *arr = (int*)malloc(size*sizeof(int));
    printf("Enter the elements: \n");
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    reverseArr(arr,size);
    printf("Reversed array:\n");
    for(int i = 0; i < size; i++) printf("%d ",arr[i]);
    return 0;
}

void reverseArr(int *arr,int size)
{
   for(int i = 0; i < size/2; i++)
   {
       int temp = arr[i];
       arr[i] = arr[size - i - 1];
       arr[size-i-1] = temp;
   }
}