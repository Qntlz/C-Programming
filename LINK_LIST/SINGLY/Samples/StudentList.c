// A Link list of students containg their name, gender, course, year level and grade

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50
#define GENDER_LEN 7
#define COURSE_LEN 5

typedef struct
{
    char *name,*gender,*course;
    int yrLvl,grade;
} Student;

typedef struct node
{
    Student info;
    struct node *next;
    
} Node, *NodePtr; 

NodePtr makeNode(char*,char*,char*,int,int);
NodePtr initialize();
void display(NodePtr);

int main()
{
    NodePtr top = NULL;
    top = initialize();
    display(top);

    return 0;
}

NodePtr makeNode(char *name,char *gender,char *course, int yrLvl, int grade)
{
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->info.name = (char*) malloc(NAME_LEN*sizeof(char));
    newNode->info.gender = (char*) malloc(GENDER_LEN*sizeof(char*));
    newNode->info.course = (char*) malloc(COURSE_LEN*sizeof(char*));

    strcpy(newNode->info.name,name);
    strcpy(newNode->info.gender,gender);
    strcpy(newNode->info.course,course);
    newNode->info.yrLvl = yrLvl;
    newNode->info.grade = grade;

    return newNode;
}

NodePtr initialize()
{
    NodePtr top = NULL, newNode = NULL, last = NULL;

    newNode = makeNode("Masao Akira", "Male","CS",1,87);
    if(top == NULL) 
    {
        top = newNode;
        last = top;
    }
    newNode = makeNode("Jamilah Sung-Hyun", "Female","IT",2,92);
    last->next = newNode;
    last = newNode;

    newNode = makeNode("U Jin Juan", "Male","IS",3,85);
    last->next = newNode;
    last = newNode;

    newNode = makeNode("Intan Mio", "Female","CS",4,96);
    last->next = newNode;
    last = newNode;

    newNode = makeNode("Juro Zhou", "Female","IS",2,94);
    last->next = newNode;
    last = newNode;

     newNode = makeNode("Kyoko Li", "Male","CS",3,88);
    last->next = newNode;
    last = newNode;

    newNode = makeNode("Hanae Katsuro", "Female","IT",4,91);
    last->next = newNode;
    last = newNode;

    newNode = makeNode("Chae-Yeong Ryosuke", "Male","IS",1,89);
    last->next = newNode;
    last = newNode;

    newNode = makeNode("Ji-Yeong Yoshimitsu", "Female","CS",2,90);
    last->next = newNode;
    last = newNode;

        newNode = makeNode("Izumi Su-Hyeon", "Male","IT",3,84);
    last->next = newNode;
    last = newNode;

    newNode = makeNode("Yōko Yoshi", "Female","IS",4,93);
    last->next = newNode;
    last = newNode;

    newNode = makeNode("Hiroshi Yuka", "Male","CS",1,81);
    last->next = newNode;
    last = newNode;

        newNode = makeNode("Tai Ji-Su", "Female","IT",2,95);
    last->next = newNode;
    last = newNode;

    newNode = makeNode("Hayate Ryōsuke", "Male","IS",3,82);
    last->next = newNode;
    last = newNode;

    return top;

}

void display(NodePtr top)
{
    printf("Students\tGender\tYear Level\tCourse\tGrade\n\n");
    while(top != NULL)
    {
        printf("%s\t%s\t%d\t%s\t%d\n",top->info.name,top->info.gender,top->info.yrLvl,top->info.course,top->info.grade);
        top = top->next;
    }
}
