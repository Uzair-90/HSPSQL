#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    char message[MAX];
    
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);

    int length = 0;
    while (message[length] != '\0' && message[length] != '\n') {
        length++;
    }

    char reversed[MAX];
    
    for (int i = 0; i < length; i++) {
        reversed[i] = message[length - 1 - i];
    }
    
    reversed[length] = '\0';
    
    printf("Reversed message: %s\n", reversed);
    
    return 0;
}

