#include <stdio.h>

#define MAX_ROW 100
#define MAX_COL 100

/*
    Write a function that accepts a 2D array and returns the maximum element in the array.
    Ask the user for the size and elements of the multi-dimensional array and use the array
    as the parameter for the created function.
*/

int getMax(int rows, int cols, int arr[rows][cols]);

int main()
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    // Ensure array size is within bounds
    if (rows > MAX_ROW || cols > MAX_COL) {
        printf("Error: maximum array size exceeded (%dx%d).\n", MAX_ROW, MAX_COL);
        return 1;
    }
    
    // Store elements in the array
    int arr[rows][cols];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) scanf("%d", &arr[i][j]);
    }

    // Get the max element in the array using the "getMax" function
    int max = getMax(rows, cols, arr);
    printf("Maximum element in the array is: %d\n", max);
    return 0;
}

int getMax(int rows, int cols, int arr[rows][cols])
{
    int max = arr[0][0]; // Initialize max with the first element
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    return max;
}
