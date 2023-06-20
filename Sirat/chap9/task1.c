#include <stdio.h>

void sort(int a[], int n) {
    
	int i;
	if (n <= 1)
        return;

    int maxIndex = 0;
    for (i = 1; i < n; i++) {
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }

    int temp = a[maxIndex];
    a[maxIndex] = a[n - 1];
    a[n - 1] = temp;

    sort(a, n - 1);
}

int main() {
    int n[10];
    int i;

    printf("Enter a series of 10 integers: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &n[i]);
    }

    sort(n, 10);

    printf("Sorted array: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", n[i]);
	}

    return 0;
}



