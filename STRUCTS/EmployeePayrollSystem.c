/*
    Language: C
    Developed By: Lance Cerenio
    Course: BSCS - 1
    Project: Employee Payroll System
    Restrictions:
        1. Can not update existing data
        2. Can not permanently store data when the program ended 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

#define NAME_LEN 30             // Set name length to 30 characters
#define BASE_MAX 100            // Set starting max to 100
#define POSITION_LEN 15         // Set position name length to 30 characters

typedef struct
{
    char name[NAME_LEN];
    int id;
    char position[POSITION_LEN];
    float salary;
    int hours;
} Employee;                                         // Information structure for each employee

int Menu();
void addEmployee(Employee*, int*);                  // Function to Add Employee
void searchEmployee(Employee*, int*);               // Function to search an employee through ID
void showPayroll(Employee*,int*);                   // Function to display total payroll of all employee
void delEmployee(Employee*,int*);                   // Function to delete employee

int main()
{

    int ctr = 0, maxMul = 1, maxQty = BASE_MAX;                             // Initialize variables
    Employee *person = (Employee *)malloc(maxQty * sizeof(Employee));       // Dynamicall allocate memory 

    while (1)
    {
        switch (Menu())
        {
        case 1:
            addEmployee(person, &ctr);
            Sleep(1500);                            // Delays for 1.5 sec
            break;
        case 2:
            delEmployee(person,&ctr);
            Sleep(3000);                            // Delays for 3 sec
            break;
        case 3:
            searchEmployee(person,&ctr);
            Sleep(3000);                            // Delays for 3 sec
            break;
        case 4:
            showPayroll(person,&ctr);
            Sleep(3000);                            // Delays for 3 sec
            break;
        case 5:
            printf("Good Bye!");
            exit(EXIT_SUCCESS); // return 0
            break;
        default:
            break;
        }
        system("cls");
    }
    if(ctr == maxQty - 1)
    {
        maxMul++;
        maxQty *= maxMul;
        person = (Employee*)realloc(person,maxQty * sizeof(Employee));
    }
    return 0;
}

int Menu()
{
    int opt;
    printf("Employee Payroll System\n");
    printf("1. Add Employee\n2.Delete Employee\n3. Search Employee\n4. Display total payroll\n5. Exit\n\n");
    scanf("%d", &opt);
    getchar();              // Remove new line
    return opt;
}

void addEmployee(Employee *p, int *ctr)
{
    printf("\nEnter employee name: ");
    fgets(p[*ctr].name, NAME_LEN, stdin);
    p[*ctr].name[strlen(p[*ctr].name) - 1] = '\0';
    printf("Enter employee ID:");
    scanf("%d", &p[*ctr].id);
    getchar();
    printf("Enter employee position: ");
    fgets(p[*ctr].position, POSITION_LEN, stdin);
    p[*ctr].position[strlen(p[*ctr].position) - 1] = '\0';
    printf("Enter employee salary: ");
    scanf("%f", &p[*ctr].salary);
    printf("Enter employee hours worked: ");
    scanf("%d", &p[*ctr].hours);
    printf("\n\nEmployee Added Successfully");
    (*ctr)++;                                       // Increments counter fot every employee added
}

void searchEmployee(Employee *p, int *ctr)
{
    int key;
    bool found = false;
    printf("Enter employee ID to search: ");
    scanf("%d", &key);

    for(int i = 0; i < *ctr; i++)
    {
        if(key == p[i].id)                     // If ID to search has been found
        {
            found = true;
            printf("\nEmployee Details: \n");
            printf("\nName: %s\nID: %d\nPosition: %s\nSalary: $%.2lf\nHours worked: %d\n",p[i].name,p[i].id,p[i].position,p[i].salary,p[i].hours);
        }
    }
    if(!found) printf("Employee Not Found!");
}

void showPayroll(Employee *p,int *ctr)
{
    double totalPayroll = 0;
    for(int i = 0; i < *ctr; i++) totalPayroll += (p[i].salary * p[i].hours);          // Sums up all employees (salary * hours) and store it in totalPayroll
    printf("Total Payroll: $%.2lf",totalPayroll);
}

void delEmployee(Employee *p,int *ctr)
{
    int key,index;
    bool found = false;
    printf("Enter employee ID to delete: ");
    scanf("%d", &key);

    for(int i = 0; i < *ctr; i++)
    {
        if(key == p[i].id)              // If the ID has been found retrieve the index
        {
            found = true;
            index = i;
            break;
        }
    }
    if(!found) printf("Employee does not exist");
    else
    {
        // Starting from the index overwrite it with the data in [index + 1] and set the limit to "< *ctr - 1"
    for(int i = index; i < *ctr - 1; i++) p[i] = p[i + 1];     
    printf("Employee Deleted");
    }

    (*ctr)--;   // Decrement the counter by one after successfully deleted
}
