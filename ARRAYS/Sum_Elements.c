#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum,size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int *arr = (int*) malloc(size*sizeof(int));
    
    printf("Enter the elements: \n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum of elements: %d",sum);
    return 0;
}