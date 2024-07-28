#include <stdio.h>

int main()
{
    int n,result;

    printf("Enter n: ");
    scanf("%d", &n);

    result = n*(n + 1)/2;
    printf("Result: %d",result);

    return 0;
}