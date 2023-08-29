#include <stdio.h>

int main() {
    int n;

    printf("Enter an odd number between 1 and 99: ");
    scanf("%d", &n);

    if (n < 1 || n > 99 || n % 2 == 0) {
        printf("Invalid input! Please enter an odd number between 1 and 99.\n");
        return 0;
    }

    int magicSquare[n][n];
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    int row = n / 2;
    int col = n - 1;


    for (int num = 1; num <= n * n; ) {
        if (row == -1 && col == n) {
            col = n - 2;
            row = 0;
        }
        else {
            if (col == n)
                col = 0;
            if (row < 0)
                row = n - 1;
        }
        if (magicSquare[row][col]) {
            col -= 2;
            row++;
            continue;
        }
        else
            magicSquare[row][col] = num++;

        col++;
        row--;
    }
    
    printf("Magic Square of size %d:\n", n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%3d ", magicSquare[i][j]);
        }
        printf("\n");
    }

    return 0;
}

