#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[30];
    int age;
    char birthday[20];
    char course[10];
} Student;

void getData(Student *, int);           // Get Student Data
void displayData(Student *, int);       // Dispay Student Data
void searchData(Student *, int); // Search a specific Student
void sortData(Student *, int);

int main()
{
    int size;
    printf("Enter number of students: ");
    scanf("%d", &size);
    Student *info = (Student *)malloc(size * sizeof(Student)); // Create dynamic array of structs for "size" amount

    getData(info, size);
    sortData(info, size);
    searchData(info, size);

    return 0;
}

void getData(Student *info, int size)
{
    getchar(); // To get the '\n'
    for (int i = 0; i < size; i++)
    {
        printf("\nStudent %d: \n", i + 1);
        printf("Enter Name: ");
        fgets(info[i].name, sizeof(info[i].name), stdin);
        info[i].name[strlen(info[i].name) - 1] = '\0';
        printf("Enter Age: ");
        scanf("%d", &info[i].age);
        getchar();
        printf("Enter Birthday[mm/dd/yy]: ");
        fgets(info[i].birthday, sizeof(info[i].birthday), stdin);
        info[i].birthday[strlen(info[i].birthday) - 1] = '\0';
        printf("Enter Course[Ex: BSIT]: ");
        fgets(info[i].course, sizeof(info[i].course), stdin);
        info[i].course[strlen(info[i].course) - 1] = '\0'; // To get the '\n'
    }
}

void displayData(Student *info, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("\n\nStudent #%d Data:\n", i + 1);
        printf("Name: %s\nAge: %d\nBirthday: %s\nCourse: %s", info[i].name, info[i].age, info[i].birthday, info[i].course);
    }
}

void searchData(Student *info, int size)
{
    char response, key[30];
    printf("\n\nSearch Student[Y/N]: ");
    scanf(" %c", &response);
    getchar();
    response = toupper(response);
    if (response == 'Y')
    {
        printf("Enter Student Name[Ex: John Doe]: ");
        fgets(key, sizeof(key), stdin);
        key[strlen(key) - 1] = '\0';
        for (int i = 0; i < size; i++) 
        {
            if (strcmp(info[i].name, key) == 0)
            {
                printf("\nStudent Found: \n");
                printf("\nStudent #%d Data:\n", i + 1);
                printf("Name: %s\nAge: %d\nBirthday: %s\nCourse: %s", info[i].name, info[i].age, info[i].birthday, info[i].course);
            } 
        }
        printf("Student Not Found!"); 
    }
}

void sortData(Student *info, int size)
{
    // Insertion Sort
    int k;
    Student temp;
    for (int i = 1; i < size; i++)
    {
        temp = info[i];
        k = i - 1;
        while (k >= 0 && strcmp(temp.name, info[k].name) < 0)
        {
            info[k + 1] = info[k];
            k = k - 1;
        }
        info[k + 1] = temp;
    }
    displayData(info, size);
}
