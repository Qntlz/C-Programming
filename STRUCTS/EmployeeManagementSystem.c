/*
    Create a program that stores the details of employees 
    (name, age, salary, and department) in a structure. 
    Print the details of the employee
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define DEPT_LEN 20
#define STR_LEN 20
#define MAX 10


typedef struct{
    char name[STR_LEN],dept[DEPT_LEN];
    int age;
    float salary;
} Employee;


void populate(Employee*);
void display(Employee*);

int ctr = 0;

int main()
{
    Employee *info = (Employee*) malloc(MAX *sizeof(Employee));

    populate(info);
    display(info);
    
    return 0;
}

void populate(Employee *i)
{
    char choice;
    printf("Enter employee details:\n");
    while(1)
    {
        printf("Employee %d\n",ctr + 1);
        printf("Name: ");
        fgets(i[ctr].name,STR_LEN,stdin);
        i[ctr].name[strlen(i[ctr].name) - 1] = '\0';

        printf("Age: ");
        scanf("%d", &i[ctr].age);

        printf("Salary: ");
        scanf("%f", &i[ctr].salary);
        getchar();
        
        printf("Department: ");
        fgets(i[ctr].dept,STR_LEN,stdin);
        i[ctr].dept[strlen(i[ctr].dept) - 1] = '\0';

        printf("Do you want to add another employee? (y/n): ");
        scanf(" %c", &choice);
        getchar();
        ctr++;
        
        if(tolower(choice) != 'y') break;
    }
}

void display(Employee *info)
{
    printf("\nEmployee details:\n");
    for(int i = 0; i < ctr; i++) printf("Name: %s\nAge: %d\nSalary: %.2f\nDepartment: %s\n\n",info[i].name,info[i].age,info[i].salary,info[i].dept);
}