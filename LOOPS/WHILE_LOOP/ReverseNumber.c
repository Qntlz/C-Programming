#include <stdio.h>

int main()
{
    int num,temp=0;
    printf("Enter a number: ");
    scanf("%d", &num);

    
    printf("Reversed number: ");
    if(num == 0) printf("0");
    while(num > 0)
    {
        temp = num % 10;
        num /= 10;
        printf("%d",temp);
    }  

    return 0;
}