/*
    Write a function called "factorial" that takes an integer value 
    as a parameter and returns the factorial of the value.
*/

#include <stdio.h>

int factorial(int);

int main()
{
    int num;
    printf("Enter an integer value: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d",num,factorial(num));
    return 0;
}

int factorial(int num)
{
    int result = 1;
    for(int i = num; i > 0; i--) result *= i;

    return result;
}