/*
    Write a program that manages the details of cars (car model, car number, rent per day, and availability status) 
    using a structure. The program should take user input to populate the car details, and then display the details 
    of all the cars in the record.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MODEL_LEN 15

typedef struct
{
    char model[MODEL_LEN];
    int num,status;           // 1 = Available 0 = Unavailable
    float price;
} Car;

int size;

void populate(Car*);
void display(Car*);

int main()
{
    printf("Enter the number of cars: ");
    scanf("%d", &size);

    Car *request = (Car*) malloc(size * sizeof(Car));

    populate(request);
    display(request);
    
    return 0;
}

void populate(Car *r)
{
    getchar();
    for(int i = 0; i < size; i++)
    {
        printf("\nEnter details of car %d:\n", i + 1);
        printf("Model: ");
        fgets(r[i].model, MODEL_LEN, stdin);
        r[i].model[strlen(r[i].model)-1] = '\0';

        printf("Number: ");
        scanf("%d", &r[i].num);

        printf("Rent per day: ");
        scanf("%f", &r[i].price);

        printf("Available (1 for available, 0 for unavailable): ");
        scanf("%d", &r[i].status);
        getchar();
    }
}
void display(Car *r)
{
    printf("\nCar details:\n");
    printf("Model\tNumber\tRent per day\tAvailable\n");
    for(int i = 0; i < size; i++) 
    {
        printf("%s\t%d\t%.2f\t",r[i].model,r[i].num,r[i].price);
        if(r[i].status == 1) printf("\tAvailable\n");
        else printf("\tUnavailable\n");
    }
}