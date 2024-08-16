#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPrime(n)) printf("%d is a prime number.\n", n);
    else printf("%d is not a prime number.\n", n);

    return 0;
}

// Function to check if a number is prime
bool isPrime(int n) {
    // Handle special cases
    if (n <= 1)
        return false;
    if (n == 2)
        return true;

    // Check from 2 to the square root of n
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}