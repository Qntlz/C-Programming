#include <stdio.h>

// Swapping 2 Variables using bitwise XOR

int main()
{
    int x = 1, y = 2;

    printf("Before Swap:\nX:%d Y:%d\n",x,y);
    x  = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("After Swap:\nX:%d Y:%d\n",x,y);
    return 0;
}