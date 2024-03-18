#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    int value = 1;
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;

    while (row_start <= row_end && col_start <= col_end)
    {
        for (int i = col_start; i <= col_end; i++)
        {
            matrix[row_start][i] = value++;
        }

        for (int i = row_start + 1; i <= row_end; i++)
        {
            matrix[i][col_end] = value++;
        }

        if (row_start < row_end && col_start < col_end)
        {
            for (int i = col_end - 1; i >= col_start; i--)
            {
                matrix[row_end][i] = value++;
            }

            for (int i = row_end - 1; i > row_start; i--)
            {
                matrix[i][col_start] = value++;
            }
        }

        row_start++;
        row_end--;
        col_start++;
        col_end--;
    }

    printf("Spiral matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}