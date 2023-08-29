#include <stdio.h>

#define GENERIC_MAX(type) \
type max_##type(type a, type b) { \
    return a > b ? a : b; \
}

// Define the generic max functions for different data types
GENERIC_MAX(int)
GENERIC_MAX(float)
GENERIC_MAX(double)

int main() {
    int intResult = max_int(10, 20);
    printf("Max of 10 and 20 (int): %d\n", intResult);

    float floatResult = max_float(3.14f, 2.71f);
    printf("Max of 3.14 and 2.71 (float): %f\n", floatResult);

    double doubleResult = max_double(5.678, 9.123);
    printf("Max of 5.678 and 9.123 (double): %lf\n", doubleResult);

    return 0;
}

