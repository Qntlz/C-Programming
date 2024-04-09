/*
    Write a function that generates and returns a personalized greeting. 
    The function should take no parameters, but should prompt the user 
    to enter their name.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50     // Assuming the length of 50 characters

char* makeGreeting();

int main()
{
    char *greeting = makeGreeting();
    printf("%s", greeting);
    free(greeting); // Freeing dynamically allocated memory
    return 0;
}

char* makeGreeting()
{
   char name[NAME_LEN]; // Using a fixed-size array for name
   char *greeting = (char*)malloc(NAME_LEN*sizeof(char)); // Allocating memory for greeting
   if (greeting == NULL) {
       fprintf(stderr, "Memory allocation failed\n");
       exit(1);
   }
   strcpy(greeting, "Hello, ");

   printf("Please enter your name: ");
   fgets(name, sizeof(name), stdin);
   name[strlen(name)-1] = '\0'; // Remove new line character
   strcat(greeting, name);
   strcat(greeting, "!");

   return greeting;
}
