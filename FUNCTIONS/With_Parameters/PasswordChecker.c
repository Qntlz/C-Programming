/*
    Write a function called check_password that takes a string as a parameter 
    representing a password, and checks if it meets the following requirements: 
    it is at least 8 characters long, contains at least one uppercase letter, 
    one lowercase letter, and one special character (!@#$%^&*). The function 
    should print "Valid password" if the password meets the requirements, and 
    "Invalid password" otherwise.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define PASS_LEN 50

void check_password(char*);

int main()
{
    char *pass = (char*)malloc(PASS_LEN*sizeof(char));
    printf("Enter password: ");
    fgets(pass, PASS_LEN, stdin);
    pass[strlen(pass) - 1] = '\0';
    check_password(pass);
    return 0;
}

void check_password(char *pass)
{
    int len = strlen(pass);
    if(!len >= 8)
    {
        printf("Invalid password");
        exit(0);
    }
    bool uppercase = false, lowercase = false, specialChar = false;
    for(int i = 0 ; i < len; i++)
    {
        if(isupper(pass[i]) && !uppercase) uppercase = true;
        if(islower(pass[i]) && !lowercase) lowercase = true;
        if((pass[i] == '!' || pass[i] == '@' || pass[i] == '#' ||pass[i] == '$' ||pass[i] == '%' ||pass[i] == '^' ||pass[i] == '&' ||pass[i] == '*') && !specialChar) specialChar = true;
    
    }
    if(uppercase && lowercase && specialChar) printf("Valid password");
    else printf("Invalid password");
}