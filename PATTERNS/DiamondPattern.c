#include <stdio.h>

int main()
{
    int rows;
    printf("Enter rows: ");
    scanf("%d", &rows);

    // Upper
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 0; j < rows - i; j++) printf(" ");
        for(int k = 0; k < (2*i) - 1; k++) printf("*");
        printf("\n");
    }
    
    // Lower
    for (int i = rows - 1; i > 0; i--)
    {
        for (int j = rows; j > i; j--) printf(" ");
        for(int k = 1; k <= (2*i) - 1; k++) printf("*");
        printf("\n");
    }
    
    return 0;
}