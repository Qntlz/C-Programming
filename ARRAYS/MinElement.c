#include <stdio.h>

/*
    Write a program that takes an array of integers as 
    input and prints the minimum element in the array.
*/

void getMin(int*,int);

int main()
{
    int size,arr[20];

    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: \n");
    getMin(arr,size);
    return 0;
}

void getMin(int *arr,int size)
{
    int min;
    min = arr[0];
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if(size == 1)
        {
            min = arr[i];
            break;
        }
        if(arr[i] < min) min = arr[i];
        else continue;
    }
    printf("Minimum element in array is: %d",min);
}