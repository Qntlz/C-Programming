/*
    Create a program that manages the records of books (book title, author, publisher, and price) 
    using a structure. Print the details of the book.
*/

#include <stdio.h>
#include <string.h>

#define TITLE_LEN 50
#define AUTHOR_LEN 30
#define PUB_LEN 30

typedef struct
{
    char title[TITLE_LEN],author[AUTHOR_LEN], publisher[PUB_LEN];
    float price;
} Book;

void populate(Book*);
void display(Book*);

int main()
{
    Book info;
    populate(&info);
    display(&info);
    return 0;
}

void populate(Book *i)
{
    printf("Enter book details:\n");
    printf("Title: ");
    fgets(i->title, TITLE_LEN, stdin);
    i->title[strlen(i->title) - 1] = '\0';

    printf("Author: ");
    fgets(i->author, AUTHOR_LEN, stdin);
    i->author[strlen(i->author) - 1] = '\0';

    printf("Publisher: ");
    fgets(i->publisher, PUB_LEN, stdin);
    i->publisher[strlen(i->publisher) - 1] = '\0';

    printf("Price: ");
    scanf("%f", &i->price);
}
void display(Book *i)
{
    printf("\nBook details:\n");
    printf("Title: %s\nAuthor: %s\nPublisher: %s\nPrice: %.2f\n",i->title,i->author,i->publisher,i->price);
}