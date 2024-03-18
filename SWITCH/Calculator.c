#include <stdio.h>

int main()
{
    float num1,num2;
    char operator;

    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%f", &num2);

    switch(operator)
    {
        case '+':
            printf("%.2lf + %.2lf = %.2lf",num1,num2,num1+num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf",num1,num2,num1-num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf",num1,num2,num1*num2);
            break;
        case '/':
            printf("%.2lf / %.2lf = %.2lf",num1,num2,num1/num2);
            break;
    }
    
    return 0;
}