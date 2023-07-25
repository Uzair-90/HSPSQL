#include <stdio.h>

int main() 
{
    for (int i = 1; i <= 128; i *= 2)
        printf("%d\n", i);

    return 0;
}