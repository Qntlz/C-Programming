
// Create a function that prints out all odd numbers from 1 to N.

#include <stdio.h>

void printOdd(int);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printOdd(n);
    return 0;
}

void printOdd(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 != 0) printf("%d\n",i);
    }
}