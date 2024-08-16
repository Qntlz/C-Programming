/*
    Implement a recursive binary search function that takes a sorted array and a target 
    value as input and returns the index of the target value if it is found in the array, 
    or -1 if it is not found.
*/

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            return binarySearch(arr, low, mid - 1, target);
        } else {
            return binarySearch(arr, mid + 1, high, target);
        }
    }
    return -1;
}

int main() {

    int n, target, index;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter %d integers in sorted order: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target value: ");
    scanf("%d", &target);
    index = binarySearch(arr, 0, n - 1, target);

    if (index != -1) printf("Target value found at index %d\n", index);
    else printf("Target value not found in the array\n");
    
    return 0;
}