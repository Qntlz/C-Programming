#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char letter, test;
    printf("Enter a letter: ");
    scanf(" %c", &letter);

    if(!isalpha(letter))
    {
        printf("Invalid input");
        exit(0);
    }

    test = toupper(letter);
    if(test == 'A' || test == 'E' || test == 'I' || test == 'O' || test == 'U') printf("%c is a vowel", test);
    else printf("%c is a consonant", test);

    return 0;
}