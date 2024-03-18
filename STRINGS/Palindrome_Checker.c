#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Note: the input is case-sensitive

int main()
{
    int len,ctr = 0;
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    len = strlen(str);
    bool palindrome = true;
    while(ctr < len/2)
    {
        if(str[ctr] == str[len - ctr - 1]) 
        {
            ctr++;
            continue;
        }
        else palindrome = false;
        ctr++;
    }
    if(palindrome) printf("Yes");
    else printf("No");

    return 0;
}