/*
    Write a recursive function power that takes two integers x 
    and y and returns the result of x raised to the power of y. 
    For example, if x is 2 and y is 3, the function should return.
*/

#include<stdio.h>

int power(int x, int y) {
    if(y == 0) {
        return 1;
    }
    return x * power(x, y-1);
}

int main() {
    int x, y;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);
    printf("%d raised to the power of %d is: %d\n", x, y, power(x, y));
    return 0;
}