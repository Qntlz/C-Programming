/*
    Write a function that accepts a 2D array and returns an array 
    containing the maximum element in each row of the input array.
*/

#include <stdio.h>
#include <stdlib.h>

int* getrowMax(int rows, int cols);

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int *result = getrowMax(rows, cols);
    if (result != NULL) {
        // Display Array
        printf("The maximum elements per row are: ");
        for (int i = 0; i < rows; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    } else {
        printf("Memory allocation failed.\n");
    }
    return 0;
}

int* getrowMax(int rows, int cols) {
    int (*arr)[cols] = malloc(rows * cols * sizeof(int));  // Allocate memory for the 2D array
    if (arr == NULL) {
        return NULL;  // Return NULL if memory allocation fails
    }

    int *maxRow = malloc(rows * sizeof(int));  // Allocate memory for the maxRow array
    if (maxRow == NULL) {
        free(arr);  // Free the 2D array memory if allocation fails
        return NULL;  // Return NULL if memory allocation fails
    }

    printf("Enter the array elements: \n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        int max = 0;  // Initialize max to the smallest possible integer value
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
        maxRow[i] = max;  // Store the maximum element for the current row
    }

    free(arr);  // Free the memory allocated for the 2D array
    return maxRow;  // Return the array containing the maximum elements per row
}
