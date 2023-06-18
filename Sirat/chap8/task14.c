#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i,j;
    int f = 0;
    int c = 0;

    printf("Enter a message: ");
    fgets(s, sizeof(s), stdin);

    int length = strlen(s);

    for (i = 0; i < length; i++) {
        if (s[i] == ' ' || s[i] == '\0' || s[i] == '\n') {
            int e = i - 1;
            while (f < e) {
                char t = s[f];
                s[f] = s[e];
                s[e] = t;
                f++;
                e--;
            }
            f = i + 1;
        }
    }
    
      for (i = 0, j = length - 1; i < j; i++, j--) {
        char t= s[i];
        s[i] = s[j];
        s[j] = t;
    }
    

    printf("Reversal of sentence: %s\n", s);

    return 0;
}

