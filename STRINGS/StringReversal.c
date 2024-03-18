#include <stdio.h>
#include <string.h>

// Prints the string in reverse

int main()
{
    int ctr;
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    ctr = strlen(str) - 1;

    while (ctr >= 0)
    {
        printf("%c", str[ctr]);
        ctr--;
    }
    return 0;
}