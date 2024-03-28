/*
    Write a program that allows the user to create a list of contacts 
    (name, phone number, and email address) and store them in a structure. 
    The program should allow the user to search for a contact by name and 
    display all the contact details.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
    char name[50];
    char phone[100];
    char email[50];
} Contact;

bool verify(char);
void makeContact(Contact*);
void printContact(Contact*);

int main()
{
    Contact persons[10];
    makeContact(persons);
    printContact(persons);
    return 0;
}

bool verify(char opt)
{
    if(opt == 'y') return true;
    else return false;
}

void makeContact(Contact *p)
{
    char opt;
    printf("Enter the contact details: \n");
    for(int i = 0; i < MAX; i++)
    {
        printf("Contact %d\n", i + 1);
        printf("Name: ");
        fgets(p[i].name, sizeof(p[i].name), stdin);
        p[i].name[strlen(p[i].name) - 1] = '\0';
        printf("Phone: ");
        fgets(p[i].phone, sizeof(p[i].phone), stdin);
        p[i].phone[strlen(p[i].phone) - 1] = '\0';
        printf("Email: ");
        fgets(p[i].email, sizeof(p[i].email), stdin);
        p[i].email[strlen(p[i].email) - 1] = '\0';
        printf("Do you want to add another contact? (y/n): ");
        scanf(" %c", &opt);
        getchar();
        opt = tolower(opt);
        if(verify(opt)) continue;
        else break;
    }
}

void printContact(Contact *p)
{
    char search[50];
    printf("Enter the name to search: ");
    fgets(search, sizeof(search), stdin);
    search[strlen(search) - 1] = '\0';

    bool found = false;
    for(int i = 0; i < MAX; i++)
    {
        if(strcmp(p[i].name, search) == 0)
        {
            printf("Contact found:\n");
            printf("Name: %s\nPhone: %s\nEmail: %s", p[i].name, p[i].phone, p[i].email);
            found = true;
            break;
        }
        else continue;
    }
    if(!found) printf("Contact not found.");
}