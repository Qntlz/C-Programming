#include <stdio.h>
#include <stdbool.h>

/*
    Write a program that takes an array of 10 integers as input and prints 
    True if the array is sorted in non-decreasing order, and False otherwise.
*/

int main()
{
    int arr[10];

    printf("Enter 10 elements in the array: \n");
    bool sorted = true;
    for(int i = 0; i < 10; i++) 
    {
        scanf("%d", &arr[i]);
        if(i > 0)
        {
            if(arr[i-1] < arr[i]) continue;
            else sorted = false;
        }
    }
    
    if(sorted) printf("True");
    else printf("False");
    return 0;
}