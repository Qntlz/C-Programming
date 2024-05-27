#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char pass[200];
    printf("Enter password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strlen(pass) - 1] = '\0';

    int len = strlen(pass);

    if(len >= 8)
    {
        bool lower = false, upper = false, digit = false;
        for(int i = 0; i < len; i++)
        {
            if(isupper(pass[i]) && upper == false) upper = true;
            if(islower(pass[i]) && lower == false) lower = true;
            if(isdigit(pass[i]) && digit == false) digit = true;
        }
        if(upper && lower && digit) printf("Password accepted.");
        else printf("Password must contain at least one uppercase letter, one lowercase letter, and one digit.");
        
    }
    else printf("Password must be at least 8 characters long.");


    return 0;
}