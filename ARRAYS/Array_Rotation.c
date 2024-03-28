#include <stdio.h>

/*
    Write a function that takes an array of integers and a number k as input and 
    uses nested loops to rotate the array k times to the right. The program should 
    print the rotated array.

    Ex:
    Enter size of array: 5
    Enter elements of array:
    1
    2
    3
    4
    5
    Enter number of rotations: 9
    Rotated array: 2 3 4 5 1
*/

#include <stdio.h>
#include <stdlib.h>

void rotateArr(int*,int,int);

int main()
{
    int size,rotations;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int *arr = (int*) malloc(size*sizeof(int));
    printf("Enter the elements of the array: \n");
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &rotations);
    rotateArr(arr,size,rotations);
    printf("Rotated Array: ");
    for(int i = 0; i < size; i++) printf("%d ",arr[i]);
    return 0;
}

void rotateArr(int *arr,int size, int rotations)
{
    for(int i = 0; i < rotations; i++)
    {
        int temp = arr[size - 1];
        for(int j = size - 1; j >= 0; j--) arr[j] = arr[j - 1];
        arr[0] = temp;
    }
}