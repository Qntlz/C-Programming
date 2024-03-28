/*
    Write a function that takes two arrays of integers as input and 
    returns a new array that contains the elements of both arrays 
    concatenated.
*/

#include <stdio.h>
#include <stdlib.h>

int* concatArr(int*,int*,int,int);

int main()
{
    int len1,len2;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &len1);
    int *firArr = (int*)malloc(len1*sizeof(int));
    printf("Enter the elements of the first array: \n");
    for(int i = 0; i < len1; i++) scanf("%d", &firArr[i]);

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &len2);
    int *secArr = (int*)malloc(len2*sizeof(int));
    printf("Enter the elements of the second array: \n");
    for(int i = 0; i < len2; i++) scanf("%d", &secArr[i]);
    int *newArr = concatArr(firArr,secArr,len1,len2);
    printf("Concatenated array:\n");
    for(int i = 0; i < len1 + len2; i++) printf("%d ",newArr[i]);
    return 0;
}

int* concatArr(int *firArr,int *secArr,int len1,int len2)
{
    int totalLen = len1 + len2;
    int *newArr = (int*)malloc(totalLen*sizeof(int));
    for(int i = 0; i < len1; i++) newArr[i] = firArr[i];
    for(int i = 0; i < len2; i++) newArr[len1 + i] = secArr[i];
    return newArr;
}