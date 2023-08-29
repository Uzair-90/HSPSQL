#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define M 10

int main() {
    int random_row, random_column;
    time_t t;
    srand((unsigned)time(&t));

    char maze[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            maze[i][j] = '.';
        }
    }

    int row = rand() % N;
    int column = rand() % M;
    char character = 'A';

    while (character <= 'Z') {
        maze[row][column] = character;
        character++;

        int direction = rand() % 4;
        
        if (direction == 0 && row > 0) {
            row--;
        } else if (direction == 1 && row < N - 1) {
            row++;
        } else if (direction == 2 && column > 0) {
            column--;
        } else if (direction == 3 && column < M - 1) {
            column++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == M - 1) {
                printf("%c\n", maze[i][j]);
            } else {
                printf("%c ", maze[i][j]);
            }
        }
    }

    return 0;
}

