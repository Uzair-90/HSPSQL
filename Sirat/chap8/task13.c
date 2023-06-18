#include <stdio.h>

int main() {
    char s[20];
    char f;

    printf("Enter a first and last name: ");
    scanf(" %c %s", &f, s);

    printf("%s, %c.\n", s, f);

    return 0;
}

