#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

#define DIGIT_HEIGHT 3
#define DIGIT_WIDTH 3
#define DIGIT_SPACING 1

#define MAX_DIGITS_SPACE (MAX_DIGITS * (DIGIT_WIDTH + DIGIT_SPACING)) - DIGIT_SPACING
#define MAX_SEGMENTS 7

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

const int digit_segments[10][7] = {
          {1, 1, 1, 1, 1, 1, 0}, 
          {0, 1, 1, 0, 0, 0, 0}, 
          {1, 1, 0, 1, 1, 0, 1}, 
          {1, 1, 1, 1, 0, 0, 1}, 
          {0, 1, 1, 0, 0, 1, 1}, 
          {1, 0, 1, 1, 0, 1, 1}, 
          {1, 0, 1, 1, 1, 1, 1}, 
          {1, 1, 1, 0, 0, 0, 0}, 
          {1, 1, 1, 1, 1, 1, 1}, 
          {1, 1, 1, 1, 0, 1, 1}  
};

const int segment_grid_pos[MAX_SEGMENTS][2] = {
    {0,   1}, 
    {1,   2}, 
    {2,   2}, 
    {2,   1}, 
    {2,   0}, 
    {1,   0}, 
    {1,   1}  
};

char digits[DIGIT_HEIGHT][MAX_DIGITS_SPACE];

int main(void)
{
    char ch;
    int position = 0;

    clear_digits_array();
    printf("Enter a number (up to 10 digits): ");
    while ((ch = getchar()) != '\n' && position < MAX_DIGITS_SPACE) {

        if (isdigit(ch)) {
            process_digit(ch - '0', position);
            position += DIGIT_WIDTH + DIGIT_SPACING;
        }
    }
    print_digits_array();

}

void clear_digits_array(void)
{
    int row, col;
    for (row = 0; row < DIGIT_HEIGHT; row++) {
        for (col = 0; col < MAX_DIGITS_SPACE; col++) 
            digits[row][col] = ' ';
    }
}

void process_digit(int digit, int starting_col)
{
    int segment, segment_row_pos, segment_col_pos;

    for (segment = 0; segment < MAX_SEGMENTS; segment++) {

        if (digit_segments[digit][segment]) {
            segment_row_pos = segment_grid_pos[segment][0];
            segment_col_pos = segment_grid_pos[segment][1] + starting_col;
            digits[segment_row_pos][segment_col_pos] = segment % 3 == 0 ? '_' : '|';
        }
    }
}

void print_digits_array(void)
{
    int row, col;
    for (row = 0; row < DIGIT_HEIGHT; row++) {
        for (col = 0; col < MAX_DIGITS_SPACE; col++) 
            printf("%c", digits[row][col]);

        printf("\n");
    }
}
