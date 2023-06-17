#include <stdio.h>

int main() {
    char firstInitial, lastName;
    char ch;
    printf("Enter your first and last name: ");
    firstInitial = getchar();
    while((ch = getchar())!=' ')
    getchar();

    while((ch = getchar())!='\n'){
        lastName = getchar();
        printf("%c",lastName);
    }

    printf(", %c\n", firstInitial);

    return 0;
}

