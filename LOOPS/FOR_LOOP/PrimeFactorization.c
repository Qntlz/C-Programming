
// Given a number N find the prime factorization of the number.

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);
void getPrimeFactor(int);

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    getPrimeFactor(n);
    return 0;
}

bool isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;

}

void getPrimeFactor(int n){

    printf("Prime Factors: "); 
    for(int i = 2; i <= n; i++){
        if( isPrime(i) ){
            int x = i;
            while(n % x == 0){
                printf("%d ", i);
                x = x * i;
            }
        }
    }
}