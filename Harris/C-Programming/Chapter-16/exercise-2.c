#include <stdio.h>

int main()
{
    struct {
        double r;
        double i;
    } s1 = {0.0, 1.0},
      s2 = {1.0, 0.0},
      s3;

    s1 = s2;

    s3.r = s1.r + s2.r;
    s3.i = s1.i + s2.i;

    printf("Struct c1: real = %.1f, imaginary = %.1f\n", s1.r, s1.i);
    printf("Struct c2: real = %.1f, imaginary = %.1f\n", s2.r, s2.i);
    printf("Struct c3: real = %.1f, imaginary = %.1f\n", s3.r, s3.i);

    return 0;
}