/*
    Write a program that asks for N then create a N x N matrix. 
    Ask for the elements of the matrix then given the matrix, 
    get the sum of the matrix diagonals then print the sum after.
*/

#include <stdio.h>
int main()
{
    int size,center,sum = 0;
    printf("Enter the size of the matrix N: ");
    scanf("%d", &size);
    int arr[size][size];
    printf("Enter the elements of the matrix\n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++) 
        {
            scanf("%d", &arr[i][j]);
            if(i == j) sum += arr[i][j];
            if(i == size - j - 1) sum += arr[i][j];
        }
    }
    if(size % 2 != 0)
    {
        center = size/2;
        sum -= arr[center][center];
    }
    printf("Sum of the diagonals is: %d",sum);
    return 0;
}