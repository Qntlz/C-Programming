#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>    // For Sleep Function

#define MAX 10
#define NAME_LEN 50

typedef struct
{
    int id, age;
    char name[NAME_LEN];
    float grade;
} Student;

int menu();
Student* initialize();                      // Function that Initializes Array of Struct Students
void addStudent(Student*);                  // Function that to add Student
void displayStudent(Student*);              // Function that display all students
void deleteStudent(Student*);               // Function to delete a student by their ID
void search(Student*);                      // Function to search a student by their ID
void sortStudent(Student*);                 // Sorts the Student(Alphabetically or By ID)
void AlphaSort(Student*);                   // Function to Sort (Alplhabetically)
void IDSort(Student*);                      // Function to Sort to ID(Increaseing)

int ctr = 0;

int main()
{
    Student *info = initialize();
    while (1)
    {
        switch (menu())
        {
        case 1:
            addStudent(info);
            break;
        case 2:
            deleteStudent(info);
            break;
        case 3:
            search(info);
            break;
        case 4:
            sortStudent(info);
            break;
        case 5:
            displayStudent(info);
            break;
        case 6:
            printf("Good Bye!");
            exit(0);
        default:
            break;
        }
    }
    
    return 0;
}

Student* initialize()
{
    return (Student *)malloc(MAX * sizeof(Student));
}

int menu()
{
    int opt;
    printf("Student Database\n\n");
    printf("1.Add Student\n2.Delete Student\n3.Search Student\n4.Sort Student\n5.Display Student\n6.Exit\n");
    scanf("%d", &opt);
    return opt;
}

void addStudent(Student *data)  
{
    printf("Enter student ID: ");
    scanf("%d", &data[ctr].id);
    getchar();
    printf("Enter Student Name: ");
    fgets(data[ctr].name, NAME_LEN, stdin);
    data[ctr].name[strlen(data[ctr].name) - 1] = '\0';
    printf("Enter Student Age: ");
    scanf("%d", &data[ctr].age);
    printf("Enter Student Grade: ");
    scanf("%f", &data[ctr].grade);
    printf("\n\nStudent Added Successfully\n\n");
    ctr++;
    Sleep(1200);
    system("cls");      // Clears the terminal
}

void displayStudent(Student *data)
{
    printf("ID\tName\t\tAge\tGrade\n");
    for (int i = 0; i < ctr; i++) printf("%d\t%s\t\t%d\t%.1f\n",data[i].id,data[i].name,data[i].age,data[i].grade);
    printf("\n\n");
    Sleep(3000);
    system("cls");
}

void deleteStudent(Student *data)
{
    int key;
    printf("Enter Studenet ID to delete: ");
    scanf("%d", &key);
    for(int i = 0; i < ctr; i++)
    {
        if(data[i].id == key)
        {
            for(int j = i; j < ctr; j++) data[j] = data[j + 1];
            ctr--;
            data = realloc(data,ctr*sizeof(Student));
            printf("Student with ID %d deleted successfully\n\n",key);
            return;
        }
    }
    printf("ID %d not Found!\n\n",key);
    Sleep(1000);
    system("cls");
}

void search(Student *data)
{
    int key;
    printf("Enter student ID to search: ");
    scanf("%d", &key);
    for (int i = 0; i < ctr; i++)
    {
        if(data[i].id == key) printf("ID: %d, Name: %s, Age: %d, Grade: %.2f",data[i].id,data[i].name,data[i].age,data[i].grade);
    }
    Sleep(3000);
    system("cls");
}

void sortStudent(Student *data)
{

    int opt;
    printf("Sort By:\n1. Alphabetically\n2. ID\n");
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        AlphaSort(data);
        displayStudent(data);
        break;
    case 2:
        IDSort(data);
        displayStudent(data);
        break;
    default:
        printf("Invalid Option!");
        break;
    }

}  

void AlphaSort(Student *data)
{
    // Sort Alphabetically using Insertion Sort
    int j;
    Student key;

    for (int i = 1; i < ctr; i++)
    {
        key = data[i];
        j = i -1;

        while (j >= 0 && strcmp(data[j].name,key.name) > 0)
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

void IDSort(Student *data)
{
     // Sort by ID using Insertion Sort
    int j;
    Student key;

    for (int i = 1; i < ctr; i++)
    {
        key = data[i];
        j = i -1;

        while (j >= 0 && data[j].id > key.id) 
        {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}