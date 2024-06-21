#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    Guide:
    diamonds = # of words
    rubies = # of r
    emerald = # of words < 4
    gold = # of vowels
    silver = # of consonants
    copper = # of spaces
*/

int diamonds = 0, rubies = 0, emerald = 0,
    gold = 0, silver = 0, copper = 0;

void check(char *);

int main()
{
    char str[6][50] = {
        "Dreaded doom darkening skies above",
        "Ravenous red raven a rising legend",
        "Ancient Arcane creature of great destruction",
        "Great Greedy source of upheaval",
        "Ominous Winged Overlord with scales of iron",
        "Nightmare of the realm and devourer of nations"};

    for (int i = 0; i < 6; i++)
    {
        // Get Word
        char *token = strtok(str[i], " ");
        
        while (token != NULL)
        {
            check(token);
            diamonds++;  // Increment word count for each token
            token = strtok(NULL, " ");
            if (token != NULL) copper++;
            
        }
    }

    printf("Diamonds: %d\nRubies: %d\nEmeralds: %d\nGold: %d\nSilver: %d\nCopper: %d\n",
           diamonds, rubies, emerald, gold, silver, copper);
           
    return 0;
}

void check(char *token)
{
    // Get Length
    int len = strlen(token);

    // Check if # of letters < 4
    if (len < 4) 
        emerald++;

    for (int i = 0; i < len; i++)
    {
        // Count how many 'r'
        if (tolower(token[i]) == 'r')
        {
            rubies++;
            silver++;
            continue;
        }

        // Vowel or Consonant
        if (tolower(token[i]) == 'a' || tolower(token[i]) == 'e' || tolower(token[i]) == 'i' || tolower(token[i]) == 'o' || tolower(token[i]) == 'u')
            gold++;
        else
            silver++;
    }
}
