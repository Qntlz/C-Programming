/*
    Write a function called calculate_bmi that takes two float values as 
    parameters representing a person's weight (in kilograms) and height 
    (in meters), and calculates and prints their BMI (body mass index) to 
    the console. The output must be in 2 decimal places.
*/

#include <stdio.h>

void calculate_bmi(float,float);

int main()
{
    float weight,height;
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    calculate_bmi(weight,height);
    return 0;
}

void calculate_bmi(float weight,float height)
{
    float BMI = weight/(height*height);
    printf("Your BMI is %.2f",BMI);
}