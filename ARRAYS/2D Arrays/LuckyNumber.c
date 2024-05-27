#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    Given m and n then an m x n matrix of distinct numbers, print all lucky 
    numbers in the matrix in any order. A lucky number is an element of the 
    matrix such that it is the minimum element in its row and maximum in its column.

    Ex:
        1 2 3
        4 5 6
        7 8 9
    
    Lucky Number: 7

*/

int main()
{
    int rows, cols;
    printf("Enter the number of rows (m): ");
    scanf("%d", &rows);
    printf("Enter the number of columns (n): ");
    scanf("%d", &cols);
    int (*arr)[cols] = malloc(rows * sizeof(*arr));      // Dynamically Allocate 2D Array
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) scanf("%d", &arr[i][j]);
    }

    printf("Lucky numbers in the matrix are: ");
    bool foundAnyLucky = false;

    // Iterate over each row to find the minimum element
    for (int i = 0; i < rows; i++) {
        int minInRow = arr[i][0];
        int minColIndex = 0;

        // Find the minimum element in the row
        for (int j = 1; j < cols; j++) {
            if (arr[i][j] < minInRow) {
                minInRow = arr[i][j];
                minColIndex = j;
            }
        }

        // Check if its the maximum in its column
        bool isMaxInCol = true;
        for (int k = 0; k < rows; k++) {
            if (arr[k][minColIndex] > minInRow) {
                isMaxInCol = false;
                break;
            }
        }

        // If it's a lucky number, print it
        if (isMaxInCol) {
            printf("%d ", minInRow);
            foundAnyLucky = true;
        }
    }

    if (!foundAnyLucky) {
        printf("No lucky numbers found.");
    }
    printf("\n");

    free(arr);  // Free the dynamically allocated memory
    return 0;
}