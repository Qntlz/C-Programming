#include <stdio.h>
#include <stdbool.h>

// Counts how many distinct numbers in the array

int main()
{
    int arr[] = {2,2,3,2};                      // Test Case
    int ctr = 1;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i = 1; i < size; i++)
    {
        int distinct = true;
        for(int j = 0; j < i; j++)
        {
            if(arr[i] == arr[j]) {
                distinct = false;
                break;
            }
        }
        if(distinct) ctr++;
    }
    printf("%d",ctr);
    return 0;  
}