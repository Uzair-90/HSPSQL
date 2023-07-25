#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define LENGTH 50+1

bool anagrams(const char *word1, const char *word2)
{
    int i, letter_count[26] = {0};

    while (*word1) {
        letter_count[*word1++ - 'A']++;
    }

    while (*word2) {
        letter_count[*word2++ - 'A']--;
    }

    for (i = 0; i < 26; i++)
        if (letter_count[i] != 0)
            return false;

    return true;
}

int main(void)
{
    char word1[LENGTH], word2[LENGTH];
    int ch, i;

    printf("Enter first word: ");
    for (i = 0; (ch = getchar()) != '\n' && i < LENGTH; i++)
        word1[i] = toupper(ch);
    word1[i] = '\0';

    printf("Enter second word: ");
    for (i = 0; (ch = getchar()) != '\n' && i < LENGTH; i++)
        word2[i] = toupper(ch);
    word2[i] = '\0';

    printf("Anagrams? %s", anagrams(word1, word2) ? "Yes" : "No");

    return 0;
}