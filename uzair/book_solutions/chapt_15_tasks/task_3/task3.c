#include<stdio.h>
#include"task3.h"

int main(){
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	quickSort(arr, 0, N - 1);
	printf("Sorted array\n");
	for (int i = 0; i < N; i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}