/*
    Write a function called "gcd" that takes two integer values as 
    parameters and returns their greatest common divisor.
*/

#include <stdio.h>

int gcd(int,int);

int main()
{
    int num1,num2;
    printf("Enter two numbers:\n");
    scanf("%d%d", &num1,&num2);
    printf("The GCD of %d and %d is: %d",num1,num2,gcd(num1,num2));
    return 0;
}

int gcd(int num1, int num2)
{
    int gcd,limit;
    if(num1 > num2) limit = num1;
    else limit = num2;

    for(int i = 1; i <= limit; i++)
    {
        if(num1 % i == 0 && num2 % i == 0) gcd = i;
    }
    return gcd;
}