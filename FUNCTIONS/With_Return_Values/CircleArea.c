/*
    Write a function that calculates and returns the area of a circle 
    with a radius entered by the user. The function should take no
    parameters, but should prompt the user to enter a radius.
*/

#include <stdio.h>

float getArea();

int main()
{
   float area = getArea();
   printf("Area of Circle: %.2f",area);
   return 0;
}

float getArea()
{
    float radius;
    const double pi = 3.14159265358979323846;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    return pi*(radius*radius);    
}