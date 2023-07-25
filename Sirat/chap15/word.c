#include <stdio.h>
#include "word.h"

int read_char(void) {
	int ch = getchar();
	
	if (ch=='\n' || ch =='\t')
		return ' ';
	
	return ch;
}

void read_word(char *word, int len) {
    int ch, pos = 0;
    
    while ((ch = read_char()) == ' ')
        ;
    
    while (ch != ' ' && ch != EOF) {
        if (pos < len - 1) { // Leave space for the null terminator
            word[pos++] = ch;
        }
        ch = read_char();
    }
    
    if (pos >= len - 1) {
        word[len - 1] = '*'; // Truncate the word and store * at the end
    }
    
    word[pos] = '\0'; // Null-terminate the word
}
