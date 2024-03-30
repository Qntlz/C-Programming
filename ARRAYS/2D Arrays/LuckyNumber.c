#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    Given m and n then an m x n matrix of distinct numbers, print all lucky 
    numbers in the matrix in any order. A lucky number is an element of the 
    matrix such that it is the minimum element in its row and maximum in its column.
*/

int main()
{
    int rows,cols,lucky;
    printf("Enter the number of rows (m): ");
    scanf("%d", &rows);
    printf("Enter the number of columns (n): ");
    scanf("%d", &cols);
    int (*arr)[cols] = malloc(rows*sizeof(*arr));      //Dynamically Allocate 2D Array
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++) scanf("%d", &arr[i][j]);
    }

    //Check Maximum in Column
    int tempMaxIndex;
    for(int i = 0; i < cols; i++)
    {
        int tempMax = arr[0][i];         // Store the value in row 0 in the each colum
        for(int j = 0; j < rows; j++)
        {
            if(arr[j][i] > tempMax) 
            {
                tempMax = arr[j][i];
                tempMaxIndex = j;
            }
        }
       
        // Check Minimum in Rows
        bool foundLucky = true;
        for(int i = 0; i < cols; i++)
        {
           if(tempMax <= arr[tempMaxIndex][i]) continue;
           else
           {
               foundLucky = false;
               break;
           }
        }
        if(foundLucky) 
        {
            lucky = tempMax;
            break;
        }
    }
    printf("Lucky numbers in the matrix are: %d",lucky);
    return 0;
}