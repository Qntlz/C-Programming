#include <stdio.h>

int main()
{
    int a = 0,b = 1,c,terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    printf("Fibonacci Series: ");
    for(int i = 0; i < terms; i++)
    {
        c = a + b;
        printf("%d, ",a);
        a = b;
        b = c;
    }
    return 0;
}