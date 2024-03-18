#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Use a while loop to iterate through the string 
and exit the loop as soon as a space character is found.
*/

int main()
{
    char str[100];
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = '\0';

    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        if(isspace(str[i])) break;
        else printf("%c",str[i]);
    }
    return 0;
}