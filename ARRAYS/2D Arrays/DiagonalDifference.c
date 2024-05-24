#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*
    Write a function that accepts a square 2D array and returns the absolute 
    difference between the sums of its diagonals. Ask for the size and elements 
    of an array and use this array as a parameter for the created function.
*/

int getdiaDiff(int size, int arr[size][size]);

int main()
{
    int size, absDiff;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    if(size > MAX){
        printf("Error: MAX size is 100\n");
        return 1;
    }
    int arr[size][size];

    // Store elements in the array
    printf("Enter elements of the array: \n");
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++) scanf("%d", &arr[i][j]);
        
    }

    // Calculate sum of diagonals
    absDiff = getdiaDiff(size, arr);
    printf("Absolute diagonal difference: %d\n", absDiff);
    return 0;
}

int getdiaDiff(int size, int arr[size][size])
{
    int dia1 = 0, dia2 = 0;

    // Get values for both diagonals
    for(int i = 0; i < size; i++){
        dia1 += arr[i][i];
        dia2 += arr[i][size - i - 1];
    }
    return abs(dia1 - dia2);  // Return Absolute Difference
}
