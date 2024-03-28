/*
    Write a function that takes an array of integers as input 
    and returns the average of all the elements in the array.
*/

#include <stdio.h>
#include <stdlib.h>

float getAve(int*,int);

int main()
{
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int *arr = (int*)malloc(size*sizeof(int));
    printf("Average of array elements: %.2lf",getAve(arr,size));
}

float getAve(int *arr,int size)
{
    float ave = 0;
    printf("Enter the elements:\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        ave += arr[i];
    }
    return ave /= size;
}