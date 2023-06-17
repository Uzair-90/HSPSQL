#include <stdio.h>
#include <ctype.h>

int main() {
    int value = 0;
    int ch;

    printf("Enter an alphabetic sequence of characters: ");

    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);

        if (ch >= 'A' && ch <= 'Z') {
            if (ch >= 'A' && ch <= 'C')
                value = 2;
            else if (ch >= 'D' && ch <= 'F')
                value = 3;
            else if(ch >= 'G' && ch <= 'I')
                value = 4;
            else if (ch >='J' && ch <= 'L')
                value = 5;
            else if (ch >= 'M' && ch <= 'O')
                value = 6;
            else if (ch >='P' && ch <= 'R')
                value  = 7;
            else if (ch >= 'S' && ch <= 'V')
                value = 8;
            else if (ch >= 'W' && ch <= 'Z')
                value = 9;
            
            printf("%d", value);
        } else {
            printf("%c", ch);
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    int value = 0;
    int ch;

    printf("Enter an alphabetic sequence of characters: \n");

    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);

        if (ch >= 'A' && ch <= 'Z') {
            if (ch >= 'A' && ch <= 'C')
                value = 2;
            else if (ch >= 'D' && ch <= 'F')
                value = 3;
            else if(ch >= 'G' && ch <= 'I')
		value = 4;
	    else if (ch >='J' && ch <= 'L')
		value = 5;
	    else if (ch >= 'M' && ch <= 'O')
		value = 6;
	    else if (ch >='P' && ch <= 'R')
		value  = 7;
	    else if (ch >= 'S' && ch <= 'V')
		value = 8;
	    else if (ch >= 'W' && ch <= 'Z')
		value = 9;

            printf("%d ", value);
        }
    }

    return 0;
}

