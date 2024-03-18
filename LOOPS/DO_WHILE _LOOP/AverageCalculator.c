#include <stdio.h>

int main()
{
    int num,ctr = 0,sum = 0;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if(num >= 0)
        {
            sum += num;
            ctr++;
        }
        else break;
    } while(1);
    printf("Average: %.2lf",(float)sum/ctr);
    return 0;
}