/*
    Given two integers d and n. Where d is the day, out of 7 days of the week, d varies from 0 to 6 as shown below.

    0 - Sunday

    1 - Monday

    2 - Tuesday

    3 - Wednesday

    4 - Thursday

    5 - Friday

    6 - Saturday

    You have to print the index for the day which is n days before the given day d.
*/

#include <stdio.h>

int main()
{
    int d, n, result;
    printf("Enter d: ");
    scanf("%d", &d);

    printf("Enter n: ");
    scanf("%d", &n);

    result = (d - n) % 7;
    if(result < 0) 
        result += 7;

    printf("%d\n", result);
    return 0;
}
