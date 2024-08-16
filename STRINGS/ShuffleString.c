/*
    You are given a string and an integer array indices of the same length.
    The string will be shuffled such that the character at the ith position
    moves to indices[i] in the shuffled string. Display the shuffled string

    Ex:

    Enter a string: string
    Enter 6 indices:
    1
    3
    2
    5
    4
    0
    Shuffled String: gsrtni 
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[255],shufstr[255];

    printf("Enter a string: ");
    fgets(str,255,stdin);
    str[strlen(str) - 1] = '\0';

    int len = strlen(str);
    printf("Enter %d indices: \n",len);
    for(int i = 0; i < len; i++)
    {
        int temp;
        scanf("%d", &temp);
        shufstr[temp] = str[i];
    }
    
    printf("Shuffled string: %s",shufstr);
    return 0;
}