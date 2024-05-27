#include <stdio.h>

int main()
{
    int arr[6];
    float ave = 0;
    for(int i = 0; i < 5; i++)
    {
        printf("Enter score %d: ", i + 1);
        scanf("%d", &arr[i]);
        ave += arr[i];
    }
    ave /= 5;
    printf("Average score: %.2lf\n", ave);
    if(ave >= 90) printf("Letter grade: A");
    else if(ave >= 80 && ave < 90) printf("Letter grade: B");
    else if(ave >= 70 && ave < 80) printf("Letter grade: C");
    else if(ave >= 60 && ave < 70) printf("Letter grade: D");
    else printf("Letter grade: F");

    return 0;
}