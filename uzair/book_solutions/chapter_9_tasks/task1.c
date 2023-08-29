#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSortRecursive(int arr[], int n, int index) {
    if (index == n - 1) {
        return;
    }

    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    swap(arr, index, minIndex);

    selectionSortRecursive(arr, n, index + 1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    selectionSortRecursive(arr, size, 0);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}

