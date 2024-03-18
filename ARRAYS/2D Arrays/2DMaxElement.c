#include <stdio.h>

int main()
{
    int rows,cols,max = 0,arr[20][20];
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++) 
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] > max) max = arr[i][j];
        }
    }
    printf("Maximum element in the array is: %d",max);
    return 0;
}