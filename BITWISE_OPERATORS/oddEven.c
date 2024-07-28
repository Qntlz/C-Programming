/*
    The & operator can be used to quickly check if a number is odd or even. 
    The value of expression (x & 1) would be non-zero only if x is odd, otherwise the value would be zero. 
*/

#include <stdio.h>

int main()
{
	int x = 20;
	(x & 1) ? printf("Odd") : printf("Even");
	return 0;
}