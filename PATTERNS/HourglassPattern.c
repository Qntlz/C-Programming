#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    //Upper
    for (int i = n; i >= 1; i--)
    {
        for(int j = n; j > i; j--) printf(" ");
        for (int k = 0; k < (2*i) - 1; k++) printf("*");
        printf("\n");
    }
    
    // Lower
    for (int i = 2; i <= n; i++)
    {
        for(int j = n; j > i; j--) printf(" ");
        for (int k = 1; k <= (2*i) - 1; k++) printf("*");
        printf("\n");
    }
}