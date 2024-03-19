#include <stdio.h>

/*
    Write a function that accepts a 2D array and returns its transpose. 
    The transpose of a matrix is obtained by interchanging its rows and columns.
*/

void transposedArr(int(*)[20],int,int);

int main()
{
    int rows,cols,arr[20][20];
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    printf("Enter elements of matrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++) scanf("%d", &arr[i][j]);
    }
    printf("Transposed matrix:\n");
    transposedArr(arr,rows,cols);
}

void transposedArr(int (*arr)[20],int rows,int cols)
{
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++) printf("%d ",arr[j][i]);
        printf("\n");
    }
}