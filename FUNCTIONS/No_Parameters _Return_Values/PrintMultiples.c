/*
    Create a function that takes in two integers A and B and prints 
    out all the multiples of A between 1 and B
*/

#include <stdio.h>

void printMultiples();

int main()
{
    printMultiples();
    return 0;
}

void printMultiples()
{
    int firstNum, secNum;
    printf("Enter first number: ");
    scanf("%d", &firstNum);
    printf("Enter second number: ");
    scanf("%d", &secNum);
    for(int i = firstNum; i <= secNum; i++)
    {
        if(i % firstNum == 0) printf("%d\n",i);
    }
}