#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num,ctr = 2;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num == 2) 
    {
        printf("%d is a prime number",num);
        return 0;
    }

    bool prime = true;
    do
    {
        if(num % ctr == 0) prime = false;
        ctr++;
    } while(ctr < num - 1);
    if(prime) printf("%d is a prime number",num);
    else printf("%d is not a prime number",num);

    return 0;
}