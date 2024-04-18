/*
    Create a program that prompts the user for an input and uses a structure 
    to store information about a circle (radius, diameter, circumference, area).
    Pass this structure as a parameter to a function that calculates the missing 
    properties (circumference, area) and displays the circle's data along with 
    the calculated properties.
*/

#include <stdio.h>
#include <math.h>

typedef struct
{
    float radius,diameter,circumference,area;
} Circle;

void populate(Circle*);
void solve(Circle*);
void display(Circle*);

const double pi = 3.14159265358979323846;

int main()
{
    Circle myCircle;
    populate(&myCircle);
    solve(&myCircle);
    display(&myCircle);
    return 0;
}

void populate(Circle *i)
{
    printf("Enter the radius of the circle: ");
    scanf("%f", &i->radius);
}
void solve(Circle *i)
{
    i->diameter = i->radius*2;
    i->circumference = 2*pi*i->radius;
    i->area = pi*i->radius*i->radius;
}

void display(Circle *i)
{
    printf("Radius: %.2f\nDiameter: %.2f\nCircumference: %.2f\nArea: %.2f",i->radius,i->diameter,i->circumference,i->area);
}