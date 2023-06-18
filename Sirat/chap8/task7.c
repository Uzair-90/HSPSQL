#include <stdio.h>

int main() {
    int s[5][5];
    int i, j;
    int tr[5] = {0};  
    int tc[5] = {0}; 

    for (i = 0; i < 5; i++) {
        printf("Enter 5 elements at row %d: ", i + 1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            tr[i] += s[i][j];
            tc[j] += s[i][j];
        }
    }

    printf("Sum of rows: ");
    for (i = 0; i < 5; i++) {
        printf("%d ",tr[i]);
    }

    printf("\nSum of columns: ");
    for (j = 0; j < 5; j++) {
        printf("%d ",tc[j]);
    }

    return 0;
}


