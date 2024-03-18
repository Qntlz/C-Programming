#include <stdio.h>

int main()
{
    int temp,size,arr[20],rot;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: \n");
    for(int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("Enter number of rotations: ");
    scanf("%d", &rot);

    for(int i = 0; i < rot; i++)
    {
        temp = arr[size - 1];
        for(int j = size - 1; j > 0; j--) 
        {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
    printf("Rotated array: ");
    for(int i = 0; i < size; i++) printf("%d ",arr[i]);

    return 0;
}   