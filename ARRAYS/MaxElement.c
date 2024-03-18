#include <stdio.h>

// Find the greatest element in the array

int main()
{
    int size,max = 0,arr[20];

    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: \n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] > max) max = arr[i];
        else continue;
    }
    printf("Maximum element in array is: %d",max);
    return 0;
}