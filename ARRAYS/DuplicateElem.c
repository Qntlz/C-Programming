#include <stdio.h>

// Finds the duplicate elements in the array

int main()
{
    int size,arr[20],dupElem = 0;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    printf("Enter %d elements in the array: \n", size);
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(arr[i] == arr[j]) dupElem = arr[i];
        }
    }
    
    if(dupElem != 0) printf("Duplicate elements in the array are: %d",dupElem);
    else printf("Duplicate elements in the array are: None");
    return 0;
}