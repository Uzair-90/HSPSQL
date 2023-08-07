#include <stdio.h>

enum {NORTH, SOUTH, EAST, WEST} directions;

int main()
{
    int x = 0, y = 0;

    directions = SOUTH;
    printf("%d\n", directions);

    switch (directions) {
        case EAST:  
                x++;
                break;
        case WEST:  
                x--;
                break;
        case SOUTH: 
                y++;
                break;
        case NORTH: 
                y--;
                break;
    }

    return 0;
}