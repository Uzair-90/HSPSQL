#include <stdio.h>

#define LINE_NUM 42

int main() {
    #line LINE_NUM "my_file.c"
    printf("Custom line number and file name.\n");
    return 0;
}

/*in the above code there is no external file naming my_file.c it is just a way to tell the 
that treat the line after this as line no 42 and of a file naming my_file.c*/


