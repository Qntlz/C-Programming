#include <stdio.h>

int main()
{
    int r,d,term;
    printf("Enter starting number: ");
    scanf("%d", &r);
    printf("Enter common ratio: ");
    scanf("%d", &d);

    term = r;
    for(int i = 0; i < 10; i++)
    {
        printf("%d ",term);
        term *= d;
    }
    return 0;
}