#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size,absDiff,dia1 = 0,dia2 = 0,arr[10][10];
    printf("Enter size of the array: ");
    scanf("%d", &size);
    printf("Enter elements of the array: \n");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++) 
        {
            scanf("%d", &arr[i][j]);
            if(i == j) dia1 += arr[i][j];
        }
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(j == size - i - 1) dia2 += arr[i][j];
        }
    }
    absDiff = abs(dia1 - dia2);
    printf("Absolute diagonal difference: %d",absDiff);

    return 0;
}