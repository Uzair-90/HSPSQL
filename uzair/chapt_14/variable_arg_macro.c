#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    int total = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

int main() {
    int result1 = sum(5, 1, 2, 3, 4, 5);
    printf("Sum of 1, 2, 3, 4, 5: %d\n", result1);

    int result2 = sum(3, 10, 20, 30);
    printf("Sum of 10, 20, 30: %d\n", result2);

    int result3 = sum(6, 2, 4, 6, 8, 10, 12);
    printf("Sum of 2, 4, 6, 8, 10, 12: %d\n", result3);

    return 0;
    
}

