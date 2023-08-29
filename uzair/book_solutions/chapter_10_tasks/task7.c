#include <stdio.h>
#include <ctype.h>

// Function to display a digit using a 7-segment display effect
void displayDigit(int digit) {
    switch (digit) {
        case 0:
            printf(" _ \n");
            printf("| | \n");
            printf("|_| \n");
            break;
        case 1:
            printf("   \n");
            printf("  | \n");
            printf("  | \n");
            break;
        case 2:
            printf(" _ \n");
            printf(" _| \n");
            printf("|_  \n");
            break;
        case 3:
            printf(" _ \n");
            printf(" _| \n");
            printf(" _| \n");
            break;
        case 4:
            printf("   \n");
            printf("|_| \n");
            printf("  | \n");
            break;
        case 5:
            printf(" _ \n");
            printf("|_  \n");
            printf(" _| \n");
            break;
        case 6:
            printf(" _ \n");
            printf("|_  \n");
            printf("|_| \n");
            break;
        case 7:
            printf(" _ \n");
            printf("  | \n");
            printf("  | \n");
            break;
        case 8:
            printf(" _ \n");
            printf("|_| \n");
            printf("|_| \n");
            break;
        case 9:
            printf(" _ \n");
            printf("|_| \n");
            printf(" _| \n");
            break;
        default:
            break;
    }
}

int main() {
    char input[100];
    
    printf("Enter a number: ");
    scanf("%s", input);
    
    for (int i = 0; input[i] != '\0'; i++) {
        if (isdigit(input[i])) {
            int digit = input[i] - '0';
            displayDigit(digit);
        }
    }
    
    return 0;
}

