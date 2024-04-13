/*
    Write a program that manages the records of students 
    (name, roll number, marks in different subjects, and total marks) 
    using a structure. Print the details of the student.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20
#define SUBS 5

typedef struct
{
    char name[NAME_LEN];
    int rollNum;
    int *score;
} ClassRecord;

void populate(ClassRecord*);
void display(ClassRecord);


int main()
{
    ClassRecord student;
    student.score = malloc(5*sizeof(int));        // Dynamically Allocate Array for the scores of each subject
    populate(&student);
    display(student);
    return 0;
}

void populate(ClassRecord *s)
{
    printf("Enter student details:\n");
    printf("Name: ");
    fgets(s->name, NAME_LEN, stdin);
    s->name[strlen(s->name) - 1] = '\0';

    printf("Roll Number: ");
    scanf("%d", &s->rollNum);

    printf("Enter marks for 5 subjects:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%d", &s->score[i]);
    }
}
void display(ClassRecord s)
{
    int sum = 0;
    printf("\nStudent details:\n");
    printf("Name: %s\nRoll Number: %d\nMarks:\n",s.name,s.rollNum);
    for(int i = 0; i < 5; i++) 
    {
        printf("Subject %d: %d\n",i + 1,s.score[i]);
        sum += s.score[i];
    }
    printf("Total Marks: %d",sum);
}