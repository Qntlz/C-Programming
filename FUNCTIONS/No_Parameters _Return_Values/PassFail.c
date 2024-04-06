/*
    Write a function that prints "Pass" or "Fail" when the user enters a 
    grade (between 0 and 100) and depending on whether the grade is above 
    or below 60.
*/

#include <stdio.h>

void checkGrade();

int main()
{
    checkGrade();
    return 0;
}

void checkGrade()
{
    int grade;
    printf("Enter the grade (between 0 and 100): ");
    scanf("%d", &grade);
    if(grade >= 60) printf("Pass");
    else printf("Fail");
}