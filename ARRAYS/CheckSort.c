#include <stdio.h>
#include <stdbool.h>

/*
    Write a program that takes an array of 10 integers as input and prints 
    True if the array is sorted in non-decreasing order, and False otherwise.
*/

int main() {
    int arr[10];
    bool sorted = true;

    printf("Enter 10 elements in the array: \n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if (i != 0 && arr[i] < arr[i - 1]) sorted = false;
    }
    
    if (sorted) printf("True");
    else printf("False");
    return 0;
}
