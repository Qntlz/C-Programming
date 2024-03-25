/*
    Write a function that accepts a 2D array and returns an array 
    containing the maximum element in each row of the input array.
*/

#include <stdio.h>
#include <stdlib.h>

int* getrowMax(int,int);

int main()
{
    int rows,cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows,&cols);
    int *result = getrowMax(rows,cols);
    printf("The maximum elements per row are: ");
    for(int i = 0; i < rows; i++) printf("%d ", result[i]);
    free(result);
    return 0;
}

int* getrowMax(int rows, int cols)
{
    int max = 0;
    int (*arr)[cols] = malloc(rows * sizeof(*arr));  // Allocate a 2D array
    int *maxRow = malloc(rows*sizeof(int));          // Allocate memory for maxRow array

    printf("Enter the array elements: \n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] > max) max = arr[i][j];      // Checks if arr[i][j] is greater than max
        }
        maxRow[i] = max;    // Stores max element for that row in maxRow array
        max = 0;            
    }
    free(arr);              // free memory of arr
    return maxRow;          // return maxRow array
}