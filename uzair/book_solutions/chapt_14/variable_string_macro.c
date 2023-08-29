#include <stdio.h>
#include <stdarg.h>

void example_function(int num_args, ...) {
    va_list args;
    va_start(args, num_args);

    for (int i = 1; i <= num_args; i++) {
        char* value = va_arg(args, char*);
        printf("Argument %d: %s\n", i, value);
    }

    va_end(args);
}

int main() {
    example_function(4, "Uzair", "Rehman", "From", "Takht-Bhai");

    return 0;
}

