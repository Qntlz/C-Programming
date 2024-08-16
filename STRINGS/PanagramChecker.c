#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/*
    A pangram (also known as a holoalphabetic sentence) is a sentence that contains every 
    letter of the alphabet at least once. The most famous example in English is:

    "The quick brown fox jumps over the lazy dog."

    This sentence uses every letter of the English alphabet at least once, making it a complete pangram.
*/

bool isPangram(const char *str) {
    int alphabet[26] = {0};  // Array to keep track of each letter's presence
    int index;

    // Traverse the given string
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {                      // Check if the character is a letter
            index = tolower(str[i]) - 'a';          // Convert letter to its respective index
            alphabet[index] = 1;                    // Mark the letter as found
        }
    }

    // Check if all letters were found
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0) {
            return false;                               // If any letter is not found, it's not a pangram
        }
    }
    return true;                                       // If all letters are found, it's a pangram
}

int main() {
    //char str[1000];
    char str[] = "Thequickbrownfoxjumpsoverthelazydog";         //Test Case

    // printf("Enter a string: ");
    // fgets(str, sizeof(str), stdin);

    if (isPangram(str)) printf("The string is a pangram.\n");
    else printf("The string is not a pangram.\n");
    
    return 0;
}
