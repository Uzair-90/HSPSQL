#include <stdio.h>

#define INTERVAL 24

int main(void)
{
    int n, i;

    printf("\nThis program prints a table of squares.\n");
    printf("Enter number of entries in table: ");

    scanf("%d", &n); 
    getchar() == ' ';

    for (i = 1; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);

        if (i % INTERVAL == 0) {
                printf("Press Enter to continue...");  
            do {
            } while (getchar() != '\n');
        }
    }
    return 0;
}
