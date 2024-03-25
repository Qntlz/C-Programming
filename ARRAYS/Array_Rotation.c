#include <stdio.h>

/*
    Write a program that takes an array of integers and a number k as input and 
    uses nested loops to rotate the array k times to the right. The program should 
    print the rotated array.

    Ex:
    Enter size of array: 5
    Enter elements of array:
    1
    2
    3
    4
    5
    Enter number of rotations: 9
    Rotated array: 2 3 4 5 1
*/

int main()
{
    int temp,size,arr[20],rot;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: \n");
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("Enter number of rotations: ");
    scanf("%d", &rot);

    for(int i = 0; i < rot; i++)
    {
        temp = arr[size - 1];
        for(int j = size - 1; j > 0; j--) 
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    printf("Rotated array: ");
    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}   