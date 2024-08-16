/*
    Write a function that takes an integer n and returns the sum of its digits. 
    For example, the sum of digits of 12345 is 1 + 2 + 3 + 4 + 5 = 15.
*/

#include <stdio.h>

int sum_of_digits(int n) {
    if (n == 0) {
        return 0;
    } else {
        return (n % 10) + sum_of_digits(n / 10);
    }
}

int main() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Sum of digits: %d", sum_of_digits(n));
    return 0;
}