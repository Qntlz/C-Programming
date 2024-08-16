// C program to find GCD of two numbers
#include <stdio.h>

// Recursive function to return gcd of a and b
int gcdRec(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// Function to return gcd of a and b (Non Recursive Method)
int gcd(int a, int b)
{
	// Find Minimum of a and b
	int result = ((a < b) ? a : b);
	while (result > 0) {
		if (a % result == 0 && b % result == 0) {
			break;
		}
		result--;
	}
	return result; // return gcd of a nd b
}

// Driver program to test above function
int main()
{
	int a = 98, b = 56;
	printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
	return 0;
}
