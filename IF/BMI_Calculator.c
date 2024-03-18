#include <stdio.h>

int main()
{
    int weight;
    float bmi, height;
    printf("Enter your weight in kilograms: ");
    scanf("%d", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    bmi =  weight/(height * height);
    printf("Your BMI is %.2lf\n", bmi);

    if(bmi <= 18.5) printf("You are underweight.");
    else if(bmi > 18.5 && bmi <= 25) printf("You are at a healthy weight.");
    else if(bmi > 25 && bmi <= 30) printf("You are overweight.");
    else printf("You are obese.");

    return 0;
}