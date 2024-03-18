/*
    Language: C
    Developed By: Lance Cerenio
    Course: BSCS - 1
    Project: Inventory Management System
    Restrictions:
        1. Can not update existing data
        2. Can not permanently store data when the program ended 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#define BASE_MAX 100                    // Set starting max to 100
#define NAME_LEN 30                     // Set name length to 30 characters
#define SUPPLIER_LEN 30                 // Set supplier name length to 30 characters

typedef struct
{
    int id;
    char name[NAME_LEN];
    float price;
    int qty;
    char supplier[SUPPLIER_LEN];
} items;                                // Information structure for each item

int Menu();                             // Main Menu Function
void addItem(items*, int*);             // Function to Add item
void search(items*, int*);              // Function to search item using item id
void displayItem(items*, int*);         // Function to display item
void makeReport(items*,int*);           // Function to display sales report

int main()
{
    int ctr = 0, maxMul = 1, maxQty = BASE_MAX;                             // Initialize variables
    items *stock = (items *)malloc(maxQty * sizeof(items));                 // Dynamically allocate memory
    while (1)
    {
        switch (Menu())
        {
        case 1:
            addItem(stock, &ctr);
            Sleep(1500);                                // Delays for 1.5 seconds
            break;
        case 2:
            search(stock, &ctr);
            Sleep(5000);                                // Delays for 5 seconds
            break;
        case 3:
            displayItem(stock,&ctr);
            Sleep(5000);
            break;
        case 4:
            makeReport(stock, &ctr);
            Sleep(5000);
            break;
        case 5:
            printf("Exiting Program.");
            exit(EXIT_SUCCESS);                         // Exits the program
            break;
        default:
            break;
        }
        if(ctr == maxQty - 1)                          // If the number of items reached to MAX - 1 dynamically increase the memory
        {
            maxMul++;
            maxQty *= maxMul;
            stock = (items*)realloc(stock, maxQty * sizeof(items));   
        }
        system("cls");
    }
    return 0;
}

int Menu()
{
    int opt;
    printf("Inventory Management System\n");
    printf("1. Add new item\n2. Search item by ID\n3. Display Inventory\n4. Generate Report\n5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &opt);
    return opt;
}

void addItem(items *s, int *ctr)
{
    printf("Enter the ID of the item: ");
    scanf("%d", &s[*ctr].id);
    getchar();                                                  // Removes the \n character when using scanf
    printf("Enter the name of the item: ");
    fgets(s[*ctr].name, NAME_LEN, stdin);
    s[*ctr].name[strlen(s[*ctr].name) - 1] = '\0';
    printf("Enter the price of the item: ");
    scanf("%f", &s[*ctr].price);
    getchar();
    printf("Enter the quantity of the item: ");
    scanf("%d", &s[*ctr].qty);
    getchar();
    printf("Enter the supplier of the item: ");
    fgets(s[*ctr].supplier, SUPPLIER_LEN, stdin);
    s[*ctr].supplier[strlen(s[*ctr].supplier) - 1] = '\0';
    printf("Item Added to Inventory.\n");
    (*ctr)++;                                                  // Increments the counter for every unique item added
}

void search(items *s, int *ctr)
{
    int key;
    bool found = false;
    printf("Enter the ID of the item to search: ");
    scanf("%d", &key);
    for (int i = 0; i < *ctr; i++)
    {
        if(key == s[i].id)                                     
        {
            printf("Item Found!\n");
            printf("\nID: %d\nName: %s\nPrice: %.2lf\nQuantity: %d\nSupplier: %s\n\n",s[i].id,s[i].name,s[i].price,s[i].qty,s[i].supplier);
            found = true;
        }
        else continue;
    }
    if(!found) printf("Item not Found!");
}

void displayItem(items *s, int *ctr)
{
    printf("\nCurrent Inventory:\n\n");
    for (int i = 0; i < *ctr; i++)
    {
        printf("ID: %d\nName: %s\nPrice: %.2lf\nQuantity: %d\nSupplier: %s\n\n",s[i].id,s[i].name,s[i].price,s[i].qty,s[i].supplier);
    }
}

void makeReport(items *s,int *ctr)
{
    int total_qty = 0;
    float sales = 0;

    for (int i = 0; i < *ctr; i++)
    {
        sales += s[i].price * s[i].qty;
        total_qty += s[i].qty;
    }
    
    printf("\nTotal Sales: $%.2lf\n", sales);
    printf("Total Quantity: %d", total_qty);
}
