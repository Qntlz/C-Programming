#include <stdio.h>
#include <string.h>
#include <ctype.h>

int convertRoman(char);

int main()
{
    int len,decimal = 0;
    char numeral[100];

    printf("Enter a Roman numeral (I, V, X, L, C, D, M): ");
    fgets(numeral, sizeof(numeral), stdin);
    numeral[strlen(numeral) - 1] = '\0';

    len = strlen(numeral);
    
    for(int i  = 0; i < len - 1; i++)
    {
        if(convertRoman(numeral[i]) < convertRoman(numeral[i + 1])) decimal -= convertRoman(numeral[i]);
        else decimal += convertRoman(numeral[i]);
    }
    decimal += convertRoman(numeral[len - 1]);
    printf("The decimal equivalent is %d", decimal);

    return 0;
}

int convertRoman(char roman)
{
    roman = toupper(roman);
    switch(roman)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}