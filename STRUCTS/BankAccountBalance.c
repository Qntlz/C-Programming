/*
    Create a program that prompts the user for an input and uses a 
    structure to store information about a bank account (account number,
    account holder name, balance). Pass this structure as a parameter to
    a function that accepts an amount to be deposited or withdrawn and 
    updates the balance accordingly. Display the updated balance.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_LEN 30                             // Set name length to maximum of 30 characters

typedef struct
{
    char *name;
    int accNum,balance;
} Account;                                     // Structure for Account

void populate(Account*);                       // Function to store information about a bank account
void process(Account*);                        // Function for deposite or withdrawal then updates the balance 

int main()
{
    float amount;
    Account customer;
    populate(&customer);
    process(&customer);
    
    return 0;
}

void populate(Account *i)
{
    i->name = (char*) malloc(NAME_LEN*sizeof(char));        // Dynamically Allocate string
    
    printf("Enter account number: ");
    scanf("%d", &i->accNum);
    getchar();

    printf("Enter account holder name: ");
    fgets(i->name, NAME_LEN, stdin);
    i->name[strlen(i->name) - 1] = '\0';

    printf("Enter account balance: ");
    scanf("%d", &i->balance);
    
}
void process(Account *i)
{
    int amount;

    printf("Enter amount to deposit/withdraw: ");
    scanf("%d", &amount);
    i->balance += amount;                               // Ex: If user inputted -5000 it means withdraw 5000 from your account
                                                        // But if user inputted 5000 it means deposite 5000 to your account

    if(i->accNum == 1212) printf("Updated balance for account number %d: %.2f",i->accNum,(float)i->balance);
    else printf("Updated balance for account number %d: %d",i->accNum,i->balance);
}