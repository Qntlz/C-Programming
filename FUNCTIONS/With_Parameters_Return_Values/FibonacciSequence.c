/*
    Write a function called "fibonacci" that takes an integer value 
    as a parameter and returns the nth number in the Fibonacci sequence.
*/

#include <stdio.h>

int fibonacci(int);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("The %dth number in the Fibonacci sequence is %d.",n,fibonacci(n));
    
    return 0;
}

int fibonacci(int n)
{
    int fir = 0, sec = 1,next;
    for(int i = 0; i < n; i++)
    {
        next = fir + sec;
        fir = sec;
        sec = next;
    }
    return fir;
}