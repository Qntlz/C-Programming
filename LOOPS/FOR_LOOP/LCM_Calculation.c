#include <stdio.h>

int main()
{
    int a, b, max, lcm;

    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);

    max = (a > b) ? a : b;

    for (lcm = max; ; lcm += max)
    {
        if (lcm % a == 0 && lcm % b == 0)
        {
            printf("The LCM of %d and %d is %d.\n", a, b, lcm);
            break;
        }
    }

    return 0;
}

// Alternative Solution:

// #include <stdio.h>

// int main()
// {
//     int fir,sec,LCM,temp1,temp2;
//     printf("Enter first number: ");
//     scanf("%d", &fir);
//     printf("Enter second number: ");
//     scanf("%d", &sec);

//     temp1 = fir;
//     temp2 = sec;
    
//     for(int i = 0; fir != sec; i++)
//     {
//         if(fir < sec) fir += temp1;
//         else sec += temp2; 
//     }
//     printf("The LCM of %d and %d is %d.",temp1,temp2,fir);
// }