
// Check the answers of each student then display there score

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define NAME_LEN 20
#define ANS_LEN 13

typedef struct
{
    int score;
    char answer[ANS_LEN],fName[NAME_LEN],lName[NAME_LEN],mIni;
} Student;

void populate(Student*,int);
void checkAnswer(Student*,char*,int);
void displayRecord(Student*,int);

int main()
{
    int size;
    char answer[] = "TTTFFTTFTF";       // Answer Key
    printf("How many students? ");
    scanf("%d", &size);

    Student *info = (Student*) malloc(MAX*sizeof(Student));
    populate(info,size);
    checkAnswer(info,answer,size);
    displayRecord(info,size);
    return 0;
}

void populate(Student *data,int size)
{
    getchar();
    for (int i = 0; i < size; i++)
    {
        printf("\nStudent %d\n\n", i + 1);
        printf("Enter First Name: ");
        fgets(data[i].fName,NAME_LEN,stdin);
        data[i].fName[strlen(data[i].fName) - 1] = '\0';
        printf("Enter Last Name: ");
        fgets(data[i].lName,NAME_LEN,stdin);
        data[i].lName[strlen(data[i].lName) - 1] = '\0';
        printf("Enter Middle Initial: ");
        scanf(" %c", &data[i].mIni);
        getchar();
        printf("Enter Answer: ");
        fgets(data[i].answer,ANS_LEN,stdin);
        data[i].answer[strlen(data[i].answer) - 1] = '\0';
        printf("\n");
    }
    
}

void checkAnswer(Student *data,char *answer,int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i].score = 0;
        for (int j = 0; j < 10; j++)    // Since there are only 10 correct answers
        {
            if(data[i].answer[j] == answer[j]) data[i].score++;
        }
    }
}

void displayRecord(Student *data,int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Student %d\n",i + 1);
        printf("%s, %s %c\nScore: %d/10\n\n",data[i].lName,data[i].fName,data[i].mIni,data[i].score);
    }
}