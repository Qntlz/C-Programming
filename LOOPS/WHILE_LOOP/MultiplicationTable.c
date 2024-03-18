#include <stdio.h>

int main()
{
    int num, start = 1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while(start <= 10)
    {
        printf("%d x %d = %d\n",num,start,num * start);
        start++;
    }
    return 0;
}