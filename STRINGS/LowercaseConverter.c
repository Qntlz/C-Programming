/*
    Write a function that takes a string entered by the user and returns 
    the string in all lowercase letters. The function should take no 
    parameters but should prompt the user to enter a string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* toLower();

int main()
{
    char* lowerStr = toLower();
    printf("Lowercase string: %s", lowerStr);
    free(lowerStr);
    return 0;
}

char* toLower()
{
    char *str = (char*)malloc(50*sizeof(char));     // Dynamicall Allocate Memory(Assuming For 50 characters)
    printf("Enter a string: ");
    fgets(str,50,stdin);
    str[strlen(str)-1] = '\0';          // Remove New Line
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        // Checks if the character is lowercase or not:
        if(str[i] == tolower(str[i])) continue;     // If it's already lowercase skip it
        else str[i] = tolower(str[i]);              // If not then convert it to lowercase
    }

    return str;
}