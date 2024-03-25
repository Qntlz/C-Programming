#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    Write a program that takes an integer array input and removes 
    duplicate elements from it, outputting the resulting array without 
    using functions.
*/

int main()
{
    int size,temp;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int *arr = (int*) malloc(size * sizeof(int));
    
    printf("Enter elements in array: \n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &temp);
        if(i == 0) arr[i] = temp;
        else
        {
            bool found = false;
            for(int j = 0; j < i; j++) if(arr[j] == temp) found = true;
            if(found)
            {
                i--;
                size--;
                continue;
            }
            else arr[i] = temp;
        }
    }
    printf("\nArray after removing duplicates: ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    return 0;   
}