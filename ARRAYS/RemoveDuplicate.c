#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    Write a program that takes an integer array input and removes 
    duplicate elements from it, outputting the resulting array without 
    using functions.
*/

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int));            // Dynamically Allocated Array for Base Values
    int *unique = (int*)malloc(size * sizeof(int));         // Dynamically Allocated Array for Unique Values
    int uniqueSize = 0;

    // Add Elements in the Array
    printf("Enter elements in array: \n");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    

    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < uniqueSize; j++) {
            if (unique[j] == arr[i]) {
                found = true;
                break;
            }
        }
        if (!found) unique[uniqueSize++] = arr[i];
    }

    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < uniqueSize; i++) printf("%d ", unique[i]);
    printf("\n");

    free(arr);
    free(unique);
    return 0;
}
