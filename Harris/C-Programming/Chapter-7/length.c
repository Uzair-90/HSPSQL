#include <stdio.h>

int main(void)
{
    char ch;
    int len = 0;

    printf("\nEnter a message: ");
    ch = getchar();

    while (ch != '\n') {
        len++;
        ch = getchar();
    }

    printf("Your message was %d character(s) long.\n\n", len);

    return 0;
}
