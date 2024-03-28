#include <stdio.h>

/*
    Write a program that takes an array of integers as 
    input and prints the minimum element in the array.
*/

int getMin(int*, int);

int main()
{
    int size, arr[20];
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size > 20 || size <= 0) {
        printf("Invalid size.\n");
        return 1; // Returning non-zero indicates an error
    }

    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int min = getMin(arr, size);
    printf("Minimum element in array: %d\n", min);
    return 0;
}

int getMin(int *arr, int size)
{
    int min = arr[0]; // Initialize min to the first element

    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i]; // Update min if current element is smaller
    }
    return min;
}