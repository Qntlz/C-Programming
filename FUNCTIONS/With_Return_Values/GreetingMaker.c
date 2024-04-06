/*
    Write a function that generates and returns a personalized greeting. 
    The function should take no parameters, but should prompt the user 
    to enter their name.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
   char name[10]; // Using a fixed-size array for name
   char *greeting = (char*)malloc(20*sizeof(char)); // Allocating memory for greeting
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
