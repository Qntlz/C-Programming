// Create a function that prints out all even numbers from 1 to N.

#include <stdio.h>

void printEven();

int main()
{
    printEven();
    return 0;
}

void printEven()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 0) printf("%d\n",i);
    }
}