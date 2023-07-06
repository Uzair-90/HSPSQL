#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_ROWS 10
#define NUM_COLS 10
#define EMPTY_CELL '.'

#define NUM_MOVES 4
#define LEFT 0
#define DOWN 1
#define UP 2
#define RIGHT 3

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
    char grid[NUM_ROWS][NUM_COLS], letter;
    generate_random_walk(grid);
    print_array(grid);
    
    return 0;
}

/* Generates a random alphabet walk through the walk array */
void generate_random_walk(char walk[10][10])
{
    char letter;
    bool potential_move[NUM_MOVES];
    int i, row, col, potential_move_count, generated_move;
    srand((unsigned) time(NULL));

    for (row = 0; row < NUM_ROWS; row++) {
        for (col = 0; col < NUM_COLS; col++) {
            walk[row][col] = '.';
        }
    }

    row = 0; col = 0;
    for (letter = 'A'; letter <= 'Z'; letter++) {

        walk[row][col] = letter;

        for (i = 0; i < NUM_MOVES; potential_move[i] = false, i++)
        potential_move_count = 0;

        if (col-1 >= 0 && walk[row][col-1] == EMPTY_CELL) {
            potential_move[LEFT] = true;
            potential_move_count++;
        }
        if (row+1 < NUM_ROWS && walk[row+1][col] == EMPTY_CELL) {
            potential_move[DOWN] = true;
            potential_move_count++;
        }
        if (row-1 >= 0 && walk[row-1][col] == EMPTY_CELL) {
            potential_move[UP] = true;
            potential_move_count++;
        }
        if (col+1 < NUM_COLS && walk[row][col+1] == EMPTY_CELL) {
            potential_move[RIGHT] = true;
            potential_move_count++;
        }

        if (potential_move_count == 0)
            break;

        while (true) {
            generated_move = rand() % NUM_MOVES;

            if (potential_move[generated_move] == true) {
                switch(generated_move) {
                    case LEFT:  col--;
                                break;
                    case DOWN:  row++;
                                break;
                    case UP:    row--;
                                break;
                    case RIGHT: col++;
                                break;
                }
                break;    
            } else {
                continue; 
            }
        }
    }
}

void print_array(char walk[10][10])
{
    int row, col;
    for (row = 0; row < 10; row++) {
        for (col = 0; col < 10; col++) {
            printf("%2c", walk[row][col]);
        }
        printf("\n");
    }
}
