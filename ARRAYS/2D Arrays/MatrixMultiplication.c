/*
    The product of two matrices is obtained by multiplying their corresponding 
    elements and summing the results.If two matrices cannot be multiplied, output 
    "Matrices cannot be multiplied." Two matrices can only be multiplied if the 
    first matrix has the same number of rows as the number of columns in the second matrix.
*/

#include <stdio.h>

int main() {
    int fRows, fCols, sRows, sCols;

    // Input dimensions for the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &fRows, &fCols);

    // Input dimensions for the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &sRows, &sCols);

    // Check if the matrices can be multiplied
    if (fCols != sRows) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }

    int firArr[fRows][fCols], secArr[sRows][sCols], tempArr[fRows][sCols];

    // Initialize tempArr to 0
    for (int i = 0; i < fRows; i++) {
        for (int j = 0; j < sCols; j++) {
            tempArr[i][j] = 0;
        }
    }

    // Input elements for the first matrix
    printf("\nEnter elements of the first matrix:\n");
    for (int i = 0; i < fRows; i++) {
        for (int j = 0; j < fCols; j++) {
            scanf("%d", &firArr[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("\nEnter elements of the second matrix:\n");
    for (int i = 0; i < sRows; i++) {
        for (int j = 0; j < sCols; j++) {
            scanf("%d", &secArr[i][j]);
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < fRows; i++) {
        for (int j = 0; j < sCols; j++) {
            for (int k = 0; k < fCols; k++) {
                tempArr[i][j] += firArr[i][k] * secArr[k][j];
            }
        }
    }

    // Output the product of the matrices
    printf("\nProduct of the matrices:\n");
    for (int i = 0; i < fRows; i++) {
        for (int j = 0; j < sCols; j++) {
            printf("%d ", tempArr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
