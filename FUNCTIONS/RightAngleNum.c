/*
    Create a function that takes in an integer N and prints out a 
    right angle made of numbers from 1 to N.
*/

#include <stdio.h>

void printNumTriangle(int);

int main()
{
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    printNumTriangle(n);
    return 0;
}

void printNumTriangle(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++) printf("%d ",j + 1);
        printf("\n");
    }
}