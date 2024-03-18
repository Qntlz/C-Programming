#include <stdio.h>

// Prints the Array in Reverse

int main()
{
    int size,arr[20];
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);
    printf("The array in reverse order is: ");
    for(int i = size - 1; i >= 0; i--) printf("%d ", arr[i]);
    return 0;
}