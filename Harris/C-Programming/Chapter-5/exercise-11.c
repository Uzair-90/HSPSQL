#include <stdio.h>

int main(void) 
{
    int area_code = 470;

    switch (area_code) {
        case 229:
            printf("Albany\n");
            break;
        case 404:
        case 470:
        case 678:
        case 770:
            printf("Atlanta\n");
            break;
        case 478:
            printf("Macon\n");
            break;
        case 706:
        case 762:
            printf("Columbus\n");
            break;
        case 912:
            printf("Savannah\n");
            break;
        default:
            printf("Area code not recongized\n");
    }

    return 0;
}