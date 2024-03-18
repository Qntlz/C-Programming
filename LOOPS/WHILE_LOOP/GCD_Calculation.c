#include <stdio.h>

int main()
{
    int fir,sec,temp,gdc;

    printf("Enter first number: ");
    scanf("%d", &fir);
    printf("Enter second number: ");
    scanf("%d", &sec);

    if(fir == 0 && sec == 0) printf("GDC of %d and %d is: 0",fir,sec);

    temp = 1;
    while(temp <= fir && temp <= sec)
    {
        if(fir % temp == 0 && sec % temp == 0) gdc = temp;
        temp++;
    }
    
    printf("GCD of %d and %d is: %d",fir,sec,gdc);
    
    return 0;
}