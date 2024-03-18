#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,temp = 0,prev = 0,next = 1,ctr = 1;
    printf("Enter the number of terms: ");
    scanf("%d", &num);

    printf("Fibonacci Series: ");
    
    while(ctr <= num)
    {
        temp = prev + next;
        printf("%d ",prev);
        prev = next;
        next = temp;
        ctr++;
    }
    return 0;  
}