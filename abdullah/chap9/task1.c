#include <stdio.h>
#define N 10

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
    int arr[N] = {0};
    
    printf("Enter the elements of array: ");
    for(int i = 0; i < N; i++){
        scanf("%d",&arr[i]);
    }

    printf("Original array: ");
    printArray(arr, N);

    selectionSortRecursive(arr, N, 0);

    printf("Sorted array: ");
    printArray(arr, N);

    return 0;
}
