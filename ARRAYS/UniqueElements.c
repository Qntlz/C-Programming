/*
    Write a function that takes an array of integers as input and 
    returns a new array that contains only the unique elements of 
    the input array.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* getUniqueElem(int*,int*,int);

int main()
{
    int size,newSize;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int *arr = (int*)malloc(size*sizeof(int));
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++) scanf("%d",&arr[i]);
    int *newArr = (int*)malloc(size*sizeof(int));
    newArr = getUniqueElem(arr,&newSize,size);
    printf("Unique Elements: ");
    for(int i = 0; i < newSize; i++) printf("%d ",newArr[i]);
    return 0;
}

int* getUniqueElem(int *arr,int *newSize,int size)
{
    int ctr = 1;
    int *newArr = (int*)malloc(size*sizeof(int));
    newArr[0] = arr[0];

    for(int i = 1; i < size; i++)
    {
        bool foundUnique = true;
        for(int j = 0; j < ctr; j++)
        {
            if(arr[i] == newArr[j]) 
            {
                foundUnique = false;
                break;
            }
        }
        if(foundUnique) 
        {
            newArr[ctr] = arr[i];
            ctr++;
        }
    }
    *newSize = ctr;
    return newArr;
}