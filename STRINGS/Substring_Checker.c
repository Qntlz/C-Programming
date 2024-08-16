#include <stdio.h>
#include <string.h>

int main()
{
    char *find;
    char str1[50],str2[50];

    printf("Enter string 1: ");
    fgets(str1, sizeof(str1),stdin);
    str1[strlen(str1) - 1] = '\0';

    printf("Enter string 2: ");
    fgets(str2, sizeof(str2),stdin);
    str2[strlen(str2) - 1] = '\0';

    find = strstr(str1,str2);   //returns a pointer to the first character of the s2 in s1, otherwise, it returns a null pointer.
    if(find) printf("%s is a subsequence of %s",str2,str1);
    else printf("%s is not a subsequence of %s",str2,str1);

    return 0;
}