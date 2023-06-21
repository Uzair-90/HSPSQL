#include <stdio.h>

int main(void) 
{
    int i = 3, j = 2;

//  returns 1 when i is greater than j, 0 when they are equal and -1 when i is smaller. 
    printf("%d", i > j ? 1 : i == j ? 0 : -1); 

    return 0;
}