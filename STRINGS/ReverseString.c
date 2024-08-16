/*
    Write a function called "reverse_string" that takes a string 
    as a parameter and returns the reversed string.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LEN 100

char* reverse_string(char*);

int main()
{
    char *str = (char*)malloc(STR_LEN*sizeof(char)),*revStr;
    printf("Enter a string: ");
    fgets(str,STR_LEN,stdin);
    str[strlen(str) - 1] = '\0';           // Remove '\n' character at the end of the string

    revStr = reverse_string(str);
    printf("The reversed string is:\n%s",revStr);

    free(revStr);
    free(str);
    
    return 0;
}

char* reverse_string(char *str)
{
    int len = strlen(str);
    char *revStr = (char*)malloc(STR_LEN*sizeof(char));     // Create a another string for the reverse form

    for(int i = 0; i < len; i++) revStr[i] = str[len - i -1];       // Store the reverse of the string 
    revStr[len] = '\0';
    return revStr;  // Return the reverse of the string
    
}