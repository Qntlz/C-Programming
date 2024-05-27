#include <stdio.h>
#include <stdlib.h>

float getDiscount(int, float);

int main()
{
    int price;
    float discount;

    printf("Enter the cost of the item: ");
    scanf("%d", &price);
    printf("Enter the discount percentage: ");
    scanf("%f", &discount);

    if(discount < 0 || discount > 100)
    {
        printf("Invalid input");
        exit(0);
    }
    else
    {
        if(price <= 50) printf("Discounted price: %.2lf", getDiscount(price, discount));
        else printf("Discounted price: %.2lf", getDiscount(price, discount));
    } 

    return 0;
}

float getDiscount(int price, float discount)
{
    if(price <= 50) return price - (price * (discount/100));
    else
    {
        float temp = price * 0.05;
        return price - (price * (discount/100)) - temp;
    }
}