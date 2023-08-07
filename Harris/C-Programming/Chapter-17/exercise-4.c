#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct point { int x, y; };
    struct rectangle { struct point upper_left, lower_right; };
    struct rectangle *pointer;

    if ((pointer = malloc(sizeof(struct rectangle))) == NULL) 
    {
        printf("Error, malloc failed.");
        exit(EXIT_FAILURE);
    }

    pointer->upper_left.x = 10;
    pointer->upper_left.y = 25;
    pointer->lower_right.x = 20;
    pointer->lower_right.y = 15;

    printf("Rectangle upper left = %d,%d\n", pointer->upper_left.x, pointer->upper_left.y);
    printf("Rectangle lower right = %d,%d\n", pointer->lower_right.x, pointer->lower_right.y);

    return 0;
}