#include <stdio.h>
#include <stdlib.h>

/*
    Write a function that accepts a square 2D array and returns the absolute 
    difference between the sums of its diagonals. Ask for the size and elements 
    of an array and use this array as a parameter for the created function.
*/

int getdiaDiff(int [][10],int);

int main()
{
    int size,absDiff,arr[10][10];
    printf("Enter size of the array: ");
    scanf("%d", &size);
    absDiff = getdiaDiff(arr,size);
    printf("Absolute diagonal difference: %d",absDiff);

    return 0;
}

int getdiaDiff(int arr[][10],int size)
{
    int dia1 = 0,dia2 = 0;
    printf("Enter elements of the array: \n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++) 
        {
            scanf("%d", &arr[i][j]);
            if(i == j) dia1 += arr[i][j];
        }
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(j == size - i - 1) dia2 += arr[i][j];
        }
    }
    return abs(dia1 - dia2);
}