#include <stdio.h>

//to see the working of #error comment the line below
#define MY_MACRO

#if !defined(MY_MACRO)
    #error "MY_MACRO is not defined. Please define it before compiling."
#endif

int main() {
    printf("The program is running correctly.\n");
    return 0;
}

