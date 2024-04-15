/*
    Write a program that manages the records of customers (name, address, phone number, and email address) 
    using a structure. Print the details of the customer.
*/

#include <stdio.h>
#include <string.h>

#define NAME_LEN 20
#define ADD_LEN 30
#define EMAIL_LEN 30
#define NUM_LEN 15

typedef struct
{
    char name[NAME_LEN],address[ADD_LEN],email[EMAIL_LEN],phoneNum[NUM_LEN];
} Customer;

void populate(Customer*);
void display(Customer*);

int main()
{
    Customer info;
    populate(&info);
    display(&info);
    return 0;
}

void populate(Customer *i)
{
    printf("Enter customer details:\n");
    printf("Name: ");
    fgets(i->name, NAME_LEN, stdin);
    i->address[strlen(i->address) - 1] = '\0';

    printf("Address: ");
    fgets(i->address, ADD_LEN, stdin);
    i->name[strlen(i->name) - 1] = '\0';

    printf("Phone Number: ");
    fgets(i->phoneNum, NUM_LEN, stdin);
    i->phoneNum[strlen(i->phoneNum) - 1] = '\0';

    printf("Email Address: ");
    fgets(i->email, EMAIL_LEN, stdin);
    i->email[strlen(i->email) - 1] = '\0';
}
void display(Customer *i)
{
    printf("\nCustomer details:\n");
    printf("Name: %s\nAddress: %sPhone Number: %s\nEmail Address: %s",i->name,i->address,i->phoneNum,i->email);
}