#include <stdio.h>

int main(void) 
{
    float x = 3983.90824f;
    printf("%-8.1e\n", x);  // Exponential notation: left justified, field size 8, to 1 decimal place.
    printf("%10.6e\n", x);  // Exponential notaion: right justified, field size 10, to 6 decimal place.
    printf("%-10.3f\n", x);  // Fixed decimal notation: left justified, field size 10, to 3 decimal place.
    printf("%6.0f\n", x);  // Fixed decimal notation: right justified, field size 6, no decimal.

    return 0;
}