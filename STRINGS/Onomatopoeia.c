#include <stdio.h>
#include <string.h>

// Task: Return the substring if between the fist occurrence and last occurrence of element X 

char* getSubstring(char*, char);

int main() {
    char string[] = "NissiN";       // Try "Hello" must returns "Hello"
    char key = 'N';
    
    char *newString = getSubstring(string, key);
    
    printf("%s", newString);  // Output the result string

    return 0;
}

char* getSubstring(char *string, char key) {
    char *start = strchr(string, key);     // Find the first occurrence of 'N'
    char *end = strrchr(string, key);      // Find the last occurrence of 'N'

    if (start != NULL && end != NULL) {
        if (start != end) {
            *end = '\0';                   // Null-terminate the string at the last occurrence
            start = start + 1;             // Move start to the character after the first 'N'
        }
    } else {
        return string;                     // If no occurrence, return the original string
    }

    return start;
}
