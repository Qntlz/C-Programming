#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int len,ctr = 0;
    char str[255];
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = '\0';

    len = strlen(str);
    for(int i = 0; i < len; i++) if(tolower(str[i]) != 'a' && tolower(str[i]) != 'e' && tolower(str[i]) != 'i' && tolower(str[i]) != 'o' && tolower(str[i]) != 'u') ctr++; 
    printf("Number of consonants: %d",ctr);
    return 0;
}