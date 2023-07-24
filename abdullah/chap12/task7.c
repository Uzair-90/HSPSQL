

#include <stdio.h>


void max_min(int a[], int size, int* max, int* min) {
    *max = *min = array[0];
    int* p;

    for (p = a; p < &a[size]; p++) {
        if (*max < *p) {
            *max = *p;
        }
        if (*min > *p) {
            *min = *p;
        }
    }
}

int main() {
    int max = 0;
    int min = 0;

    int a[10] = { 1, 2, 3, 4, 5,6,6,7,8,9 };

    max_min(a, 10, &max, &min);

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    

    return 0;
}
