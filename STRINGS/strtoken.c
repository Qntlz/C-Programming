#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World! How are you?";
    char delim[] = " ,!?";  // specify the delimiters

    // get the first token
    char *token = strtok(str, delim);

    // loop through the string to extract all tokens
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }

    return 0;
}
