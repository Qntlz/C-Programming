#include <stdio.h>

int main()
{
    int n = 5;

    // Inverted Right Angle

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {   
           if(j < n - i) printf(" ");
           else printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // Top Inverted
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i; j++) printf("*");
        printf("\n");
    }
    
    return 0;
}

