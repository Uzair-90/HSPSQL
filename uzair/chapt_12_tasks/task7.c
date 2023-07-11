#include<stdio.h>

void max_min(int array[], int size, int* max, int* min) {
    *max = *min = array[0];
    int* p;

    for (p = array; p < &array[size]; p++) {
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

    int array[5] = { 1, 2, 3, 4, 5 };

    max_min(array, 5, &max, &min);

    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}

