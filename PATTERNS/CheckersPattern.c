#include <stdio.h>

int main()
{
    int rows;
    printf("Enter rows: ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if((i + j) % 2 == 0) printf("W ");
            else printf("B ");
        }
        printf("\n");
    }
    return 0;
}