#include <stdio.h>
#include <stdbool.h>

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    bool perfectSquare = false;
    for(int i = 0; i < num; i++) if(i * i == num) perfectSquare = true;
    if(perfectSquare) printf("%d is a perfect square",num);
    else printf("%d is not a perfect square",num);
    return 0;   
}