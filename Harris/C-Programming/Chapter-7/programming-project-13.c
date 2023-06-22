#include <stdio.h>

#define LAST_WORD 1    /* the last word is not counted in the switch */

int main(void)
{
    char input;
    int characters = 0, words = LAST_WORD;

    printf("\nEnter a sentence: ");

    while ((input = getchar()) != '\n') {
        switch (input) {
            case ' ':  
                words++;
                break;
            default:
                characters++;
                break;
        }
    }

    printf("Characters = %d\n", characters);
    printf("Words = %d\n", words);
    printf("Average word length %.1f\n\n", (float) characters / words);

    return 0;
}
