// Create a function that prints out all even numbers from 1 to N.

#include <stdio.h>

void printEven(int);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printEven(n);
    return 0;
}

void printEven(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 0) printf("%d\n",i);
    }
}