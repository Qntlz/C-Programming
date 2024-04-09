/*
    Write a function called meters_to_feet that takes a float value in meters 
    as a parameter and converts it to feet. The result should be printed on the 
    console. The output must be in 2 decimal places.
*/

#include <stdio.h>

void meters_to_feet(float);

int main()
{
    float len;
    printf("Enter length in meters: ");
    scanf("%f", &len);
    meters_to_feet(len);
    return 0;
}

void meters_to_feet(float len)
{
    printf("%.2f meters is equal to %.2f feet",len,len*3.28);
}