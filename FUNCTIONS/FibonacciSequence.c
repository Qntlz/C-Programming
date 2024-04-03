/*
    Create a function that takes in an integer N and prints 
    out the first N numbers of the Fibonacci sequence.
*/

#include <stdio.h>

void printFibo(int);

int main()
{
    int terms;
    printf("Enter the number of terms: ");
    scanf("%d", &terms);
    printFibo(terms);
    return 0;
}

void printFibo(int terms)
{
    int fir = 0, sec = 1, next;
    if(terms == 0) 
    {
        printf("Fibonacci sequence of %d terms:",terms);
        exit(0);
    }
    printf("Fibonacci sequence of %d terms: 0 1 ",terms);
    for(int i = 0; i < terms-2; i++)
    {
        next = fir + sec;
        printf("%d ",next);
        fir = sec;
        sec = next;
    }
}