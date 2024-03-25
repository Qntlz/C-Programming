#include <stdio.h>

/*
    Write a function that takes an array of integers as 
    input and prints the maximum element in the array.
*/

void getMax(int*,int);

int main()
{
    int size,arr[20];

    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: \n");
    getMax(arr,size);
    return 0;
}

void getMax(int *arr, int size)
{
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] > max) max = arr[i];
        else continue;
    }
    printf("Maximum element in array is: %d",max);
}