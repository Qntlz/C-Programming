/*
    Write a function named prime_factors that takes an integer 
    as input and returns a list of its prime factors. The output 
    should be in ascending order and allows duplicates. The function 
    should take no parameters.
*/

#include <stdio.h>
#include <stdlib.h>

int* prime_factors();

int ctr = 0;        // Iniatialize global variable counter

int main() {
    int* result = prime_factors();
    for(int i = 0; i < ctr; i++) printf("%d ",result[i]);
    return 0;
}

int* prime_factors() {
    int num,temp;
    int *prime = (int*)malloc(20*sizeof(int));
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    temp = num;
    for(int i = 2; i <= temp; i++) {
        
        // Stores the factors in an array
        while(temp % i == 0) {
            prime[ctr] = i;
            temp /= i;
            ctr++;
        }
    }
    printf("The prime factors of %d are: ",num);
    return prime;
}
