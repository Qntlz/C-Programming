// Write a function called "sum" that takes two integer values as parameters and returns their sum.

#include <stdio.h>

int sum(int,int);

int main()
{
    int x,y,result;
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);

    result = sum(x,y);
    printf("The sum is %d",result);
    
    return 0;
}

int sum(int x,int y)
{
    return x + y;
}