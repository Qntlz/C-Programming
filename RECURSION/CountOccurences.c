// Write a recursive function to count the number of occurrences of a specific value in a list.

#include <stdio.h>
#include <stdlib.h>

int countOccurrences(int arr[], int size, int target){
    if (size == 0){
        return 0;
    }
    int count = countOccurrences(arr, size - 1, target);
    if (arr[size - 1] == target){
        count++;
    }
    return count;
}

int main(){
    int size, target, count;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
   
    int *arr = (int*)malloc(size*sizeof(int));

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);

    printf("Enter the target value: ");
    scanf("%d", &target);
    
    count = countOccurrences(arr, size, target);
    printf("The target value appears %d times in the list.\n", count);
    return 0;
}