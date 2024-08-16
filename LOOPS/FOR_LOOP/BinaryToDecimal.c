#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Driver code
int main()
{
	char binaryNumber[] = "1001";
	int bin, dec = 0;
	
	bin = atoi(binaryNumber);               // Converts string to integer

	for(int i = 0; bin; i++, bin /= 10)
		if (bin % 10)
			dec += pow(2, i);

	printf("%d", dec);

	return 0;
}
// This code is contributed by whysodarkbro


/*
    IF the binary was given as a string:

    int dec = 0, base = 1;
    int len = strlen(str);
    
    
    for(int i = len - 1; i >= 0; i--)
    {
        int tempNum = str[i] - 48;
        dec += (tempNum * base);
        base *= 2;
    }

*/