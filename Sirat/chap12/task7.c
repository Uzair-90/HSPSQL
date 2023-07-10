#include <stdio.h>

#define N 10

void max_min(int *a, int n, int *max, int *min);

int main(void) {
    int b[N], big, small;
    int *p;
    
    printf("Enter %d numbers: ", N);
    for (p = b; p < b + N; p++)
        scanf("%d", p);
        
    p = b;   

    max_min(p, N, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

void max_min(int *a, int n, int *max, int *min) {
    *max = *min = *a;
    int i=0;
    for (i = 1; i < n; i++) {
        if (*(a + i) > *max)
            *max = *(a + i);
        else if (*(a + i) < *min)
            *min = *(a + i);
    }
}




