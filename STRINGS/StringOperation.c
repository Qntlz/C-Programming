/*
    Given a string involving operation of two numbers, 
    print the resulting number after. The operations are 
    '+' , '-', '*', and '/'. Print the answers in two decimal places.
*/

#include <stdio.h>
#include <string.h>

float solve(int,int,char);

int main()
{
    int num1,num2;
    char opt,str[10];
    printf("Enter the operation: ");
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = '\0';

    sscanf(str,"%d %c %d",&num1,&opt,&num2);
    printf("Result: %.2lf",solve(num1,num2,opt));

    return 0;
}

float solve(int x,int y,char opt)
{
    switch(opt)
    {
        case '+':
            return x + y;
            break;
        case '-':
            return x - y;
            break;
        case '*':
            return x * y;
            break;
        case '/':
            return (float)x / y;
            break;
        default:
            return -1;
            break;
    }
    return 0;
}