#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 20

int read_line(char str[], int n) {
    int ch, i = 0;
    while (i < n - 1 && (ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

void sort_words(char* words[], int num_words) {
    char* temp;
    int i,j;

    for ( i = 0; i < num_words - 1; i++) {
        for ( j = 0; j < num_words - i - 1; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}

int main() {
    int max_words = 2; 
    int num_words = 0; 
    char** words = malloc(max_words * sizeof(char));

    if (words == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1) {
        if (num_words == max_words) {
            max_words *= 2;
            char** temp = realloc(words, max_words * sizeof(char));

            if (temp == NULL) {
                printf("Memory allocation failed.\n");
                break;
            }

            words = temp;
        }

        words[num_words] = (char*)malloc((WORD_LEN + 1) * sizeof(char));

        if (words[num_words] == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }

        printf("Enter word: ");
        read_line(words[num_words], WORD_LEN + 1);

       
        if (strcmp(words[num_words], " ") == 0) {
            break;
        }

        num_words++; 
    }

    sort_words(words, num_words);
	int i;
    printf("In sorted order: ");
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        free(words[i]);
    }

    free(words);

return 0;
}
