#include <stdio.h>

int main() {
    int decimal, remainder, binary = 0, base = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    while(decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * base;
        decimal /= 2;
        base *= 10;
    }

    printf("Binary equivalent: %d", binary);

    return 0;
}