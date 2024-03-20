/*
    The product of two matrices is obtained by multiplying their corresponding 
    elements and summing the results.If two matrices cannot be multiplied, output 
    "Matrices cannot be multiplied." Two matrices can only be multiplied if the 
    first matrix has the same number of rows as the number of columns in the second matrix.
*/

#include <stdio.h>

int main()
{
    int fRows,fCols,sRows,sCols,firArr[20][20],secArr[20][20],tempArr[10][10] = {0};

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d",&fRows,&fCols);
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d",&sRows,&sCols);

    if(fCols != sRows)
    {
        printf("Matrices cannot be multiplied.");
        return 0;
    }

    printf("\nEnter elements of the first matrix:\n");
    for(int i = 0; i < fRows; i++)
    {
        for(int j = 0; j < fCols; j++) scanf("%d",&firArr[i][j]);
    }

    printf("\nEnter elements of the second matrix:\n");
    for(int i = 0; i < sRows; i++)
    {
        for(int j = 0; j < sCols; j++) scanf("%d",&secArr[i][j]);
    }

    // Solve Matrix Multiplication
    for(int i = 0; i < sCols; i++)
    {
        for(int j = 0; j < fRows; j++)
        {
            for(int k = 0; k < sRows; k++)
            {
               tempArr[j][i] += firArr[j][k] * secArr[k][i];
            }
        }
    }
    printf("\nProduct of the matrices: \n");
    for(int i = 0; i < fRows; i++)
    {
        for(int j = 0; j < sCols; j++) printf("%d ",tempArr[i][j]);
        printf("\n");
    }
    return 0;
}