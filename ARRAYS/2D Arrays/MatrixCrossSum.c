/*
    Write a program that asks for N then create a N x N matrix. 
    Ask for the elements of the matrix then given the matrix, 
    get the sum of the matrix diagonals then print the sum after.
*/

#include <stdio.h>
#include <stdlib.h>  // For malloc and free

int main() {
    int size, sum = 0;

    // Input for the size of the matrix
    printf("Enter the size of the matrix N: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid input! Please enter a positive integer for the size.\n");
        return 1;
    }

    // Dynamic memory allocation for the matrix
    int **arr = (int**) malloc(size*sizeof(int*));
    for (int i = 0; i < size; i++) arr[i] = (int*) malloc(size*sizeof(int));

    // Input for the elements of the matrix
    printf("Enter the elements of the matrix\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                printf("Invalid input! Please enter integers only.\n");
                // Free the allocated memory before returning
                for (int k = 0; k < size; k++) {
                    free(arr[k]);
                }
                free(arr);
                return 1;
            }
            if (i == j) sum += arr[i][j];  // Primary diagonal
            if (i == size - j - 1) sum += arr[i][j];  // Secondary diagonal
        }
    }

    // Adjust the sum if the matrix size is odd (to avoid double-counting the center element)
    if (size % 2 != 0) {
        int center = size / 2;
        sum -= arr[center][center];
    }

    // Print the sum of the diagonals
    printf("Sum of the diagonals is: %d\n", sum);

    // Free the allocated memory
    for (int i = 0; i < size; i++) free(arr[i]);
    
    free(arr);

    return 0;
}
