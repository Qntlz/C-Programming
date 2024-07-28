#include <stdio.h>

int getLastDigit(int);

int main()
{
    int n,lastDigit;
    printf("Enter a number: ");
    scanf("%d", &n);
    lastDigit = getLastDigit(n);
    printf("Last Digit: %d", lastDigit);
    return 0;
}

int getLastDigit(int n)
{
    return (n > 0) ? n % 10 : -(n % 10);
}