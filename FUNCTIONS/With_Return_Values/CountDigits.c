/*
    Write a function named count_digits that takes an integer 
    as input and returns the number of digits in the integer. 
    The function should take no parameters.
*/

#include <stdio.h>

int count_digits();

int main()
{
    int digits = count_digits();
    printf("Number of digits: %d", digits);
    return 0;
}

int count_digits()
{
    int num,ctr = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);
    while(num != 0)
    {
        num /= 10;
        ctr++;
    }
    return ctr;
}
