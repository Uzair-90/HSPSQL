#include <stdio.h>

// Uncomment the line below to enable DEBUG mode
//Comment the line below to disable DEBUG mode
 #define DEBUG

int main() {
    int num1 = 10;
    int num2 = 5;
    int result;

    // Check if DEBUG macro is defined
    #ifdef DEBUG
        printf("Debug mode is enabled.\n");
        printf("Calculating the sum...\n");
    #endif

    result = num1 + num2;

    #ifdef DEBUG
        printf("The sum of %d and %d is: %d\n", num1, num2, result);
    #else
        printf("The result is: %d\n", result);
    #endif

    return 0;
}

