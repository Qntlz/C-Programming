#include <stdio.h>
#include <string.h>

// Counting occurrences of a character in a string

int main()
{
    int len,ctr = 0;
    char str[255],find;
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    str[strlen(str) - 1] = '\0';

    printf("Enter a character to count: ");
    scanf(" %c", &find);

    len = strlen(str);
    for(int i = 0; i < len; i++) if(str[i] == find) ctr++;
    printf("The character '%c' appears %d times in the string.",find,ctr);
    
}