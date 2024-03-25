#include <stdio.h>

/*
    Write a function that accepts a 2D array and returns the maximum element in the array.
    Ask the user for the size and elements of the multi-dimensional array and use the array
    as the parameter for the created function.
*/

int getMax(int arr[][20], int rows, int cols);

int main()
{
    int rows, cols, max = 0, arr[20][20];
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    max = getMax(arr, rows, cols);
    printf("Maximum element in the array is: %d", max);
    return 0;
}

int getMax(int arr[][20], int rows, int cols)
{
    int max = arr[0][0];                            // Initialize max with the first element
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    return max;
}
