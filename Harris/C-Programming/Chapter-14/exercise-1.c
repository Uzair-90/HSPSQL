#include <stdio.h>

#define CUBE(x) ((x) * (x) * (x))
#define REMAINDER(n) ((n) % 4)
#define PRODUCT(x, y) ((x) + (y) < 100 ? 1 : 0)

int main(void)
{
    int a = 2, b = 10;
    float c = 5;
    printf("%f\n", CUBE(c));
    printf("%d\n", REMAINDER(a));
    printf("%d\n", PRODUCT(a, b));

    return 0;
}