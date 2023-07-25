#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension)
{

    while (*file_name) {
        if (*file_name++ == '.') {
            strcpy(extension, file_name);
            return;
        }
    }
    
    strcpy(extension, "");
}

int main(void)
{
    char filename[] = "demo.txt";
    char extension[20];

    get_extension(filename, extension);
    printf("Filename: %s, Extension: %s", filename, extension);

    return 0;
}