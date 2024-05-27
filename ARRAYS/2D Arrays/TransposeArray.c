#include <stdio.h>
#include <stdlib.h>

/*
    Write a function that accepts a 2D array and returns its transpose. 
    The transpose of a matrix is obtained by interchanging its rows and columns.
*/

int** transposedArr(int** arr, int rows, int cols);

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Dynamic allocation of the 2D array
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // Input elements of the matrix
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Get the transposed matrix
    int** transposeArr = transposedArr(arr, rows, cols);
    
    // Print the transposed matrix
    printf("Transposed matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transposeArr[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    for (int i = 0; i < cols; i++) {
        free(transposeArr[i]);
    }
    free(transposeArr);

    return 0;
}

int** transposedArr(int** arr, int rows, int cols) {
    // Dynamic allocation of the transpose 2D array
    int** transposeArr = (int**)malloc(cols * sizeof(int*));
    for (int i = 0; i < cols; i++) {
        transposeArr[i] = (int*)malloc(rows * sizeof(int));
    }

    // Transpose the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposeArr[j][i] = arr[i][j];
        }
    }

    return transposeArr;
}
