#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    Use a for loop to iterate through the words in the sentence and 
    exit the loop as soon as a word is found that contains the letter 
    'z'. Print the number of words that were processed before the word 
    containing 'z' was found.
*/

int main() {
    char str[100];
    int count = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') count++;
        else if (tolower(str[i]) == 'z') break;
        
    }
    printf("Number of words processed before finding the word containing 'z': %d\n", count + 1);

    return 0;
}