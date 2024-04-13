/*
    Create a program that allows a user to enter the information of 2 students 
    (name, age, and grade). Store the information in a structure and display 
    it in a table format.
*/

#include <stdio.h>
#include <string.h>

#define MAX 2
#define NAME_LEN 20

typedef struct
{
    char name[NAME_LEN];
    int age;
    float grade;
} Student;                          // Student Structure containing information of a student

void populate(Student*);            // Function to populate an array of Student structure
void display(Student*);             // Function to display the contents in a Student structure

int main()
{
    Student info[MAX];

    populate(info);
    display(info);
    
    return 0;
}

void populate(Student *info)
{
    for(int i = 0; i < MAX; i++)
    {
        printf("Enter the name of student %d: ",i + 1);
        fgets(info[i].name, NAME_LEN, stdin);
        info[i].name[strlen(info[i].name) - 1] = '\0';

        printf("Enter the age of student %d: ", i + 1);
        scanf("%d", &info[i].age);

        printf("Enter the grade of student %d: ",i + 1);
        scanf("%f", &info[i].grade);
        getchar();
    }   
}

void display(Student *info)
{
    printf("Name\tAge\tGrade\n");
    for(int i = 0; i < MAX; i++)
    {
        printf("%s\t%d\t%.2f\n",info[i].name,info[i].age,info[i].grade);
    }
}