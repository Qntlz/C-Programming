/*
    Write a function called "is_palindrome" that takes a string as a 
    parameter and returns true if the string is a palindrome, false
     otherwise
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define STR_LEN 50                  // Assume string with a maximum of 50 characters

bool is_palindrome(char*);

int main()
{
    char *str = (char*)malloc(STR_LEN*sizeof(char));
    printf("Enter a string: ");
    fgets(str,STR_LEN,stdin);
    str[strlen(str)-1] = '\0';

    if(is_palindrome(str)) printf("The string is a palindrome.");
    else printf("The string is not a palindrome.");
        
    return 0;
}


bool is_palindrome(char *str)
{
    int len = strlen(str);                  // Get string length
    for(int i=0; i < len/2; i++)
    {
        if(tolower(str[i]) == tolower(str[len - i - 1])) continue;  // Convert the letter to lowercase and compare
        else return false;
    }
    return true;
}