#include <stdio.h>

// Find the smallest element in the array

int main()
{
    int size,min = 0,arr[20];

    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: \n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        if(size == 1)
        {
            min = arr[i];
            break;
        }
        if(arr[i] < min) min = arr[i];
        else continue;
    }
    printf("Minimum element in array is: %d",min);
    return 0;
}