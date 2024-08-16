#include <stdio.h>

int binary_to_decimal(int);

int main()
{
    int binary;

    printf("Enter a binary: ");
    scanf("%d", &binary);

    printf("Decimarl: %d",binary_to_decimal(binary));

    return 0;
}

int binary_to_decimal(int B)
{
    int digit = 0, power = 0, temp;

    while (B != 0) {
        temp = B % 10; // Get the last digit
        if (temp == 1) {
            digit += 1 << power; // 1 << power is equivalent to 2^power
        }
        power++; // Increase the power for the next digit
        B /= 10; // Remove the last digit from the binary number
    }
	return digit;
}