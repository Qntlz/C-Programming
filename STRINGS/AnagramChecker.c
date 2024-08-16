#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to sort the characters of a string
void sortString(char* str) {
    int n = strlen(str);
    for (int i = 1; i < n; i++) {
        char key = str[i];
        int j = i - 1;

        // Move elements of str[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = key;
    }
}

// Function to check if two strings are anagrams
bool isAnagram(const char* a, const char* b) {
    // If lengths are not equal, they can't be anagrams
    if (strlen(a) != strlen(b)) {
        return false;
    }

    // Create copies of the strings to sort
    char* sortedA = strdup(a);
    char* sortedB = strdup(b);

    if (sortedA == NULL || sortedB == NULL) {
        // Handle memory allocation failure
        return false;
    }

    // Sort the copied strings
    sortString(sortedA);
    sortString(sortedB);

    // Compare the sorted strings
    bool result = strcmp(sortedA, sortedB) == 0;

    // Free the allocated memory for the copies
    free(sortedA);
    free(sortedB);

    return result;
}

int main() {
    const char* str1 = "listen";
    const char* str2 = "silent";

    if (isAnagram(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    // Print the original strings to show they are unchanged
    printf("Original strings:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}
