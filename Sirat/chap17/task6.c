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

int compare_strings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    int max_words = 2; 
    int num_words = 0; 
    char** words = (char**)malloc(max_words * sizeof(char*));

    if (words == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1) {
        if (num_words == max_words) {
            max_words *= 2;
            char** temp = (char**)realloc(words, max_words * sizeof(char*));

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
            free(words[num_words]);
            break;
        }

        num_words++; 
    }

    qsort(words, num_words, sizeof(char*), compare_strings);
	int i;
    printf("In sorted order: ");
    for (i = 0; i < num_words; i++) {
        printf("%s ", words[i]);
        free(words[i]);
    }

    free(words);

    return 0;
}

