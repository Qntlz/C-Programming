#include <stdio.h>

int main()
{
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    if(age < 0) printf("Invalid age entered.");
    else if(age >= 60) printf("You are a senior.");
    else if(age >= 30 && age < 60) printf("You are an adult.");
    else if(age >= 20 && age < 30) printf("You are a young adult.");
    else if(age >= 13 && age < 20) printf("You are a teenager.");
    else printf("You are a child.");

    return 0;
}