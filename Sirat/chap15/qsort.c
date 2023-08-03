#include <stdio.h>
#include "quicksort.h"
#define N 10

int main(void)
{
	int a[N],i;
	printf("enter %d number to be sorted: ",N);
	for (i=0;i<N;i++)
	scanf("%d",&a[i]);
	
	quicksort(a,0,N-1);
	printf("in sorted order: ");
	for (i=0;i<N;i++)
		printf("%d",a[i]);
	
	return 0;	
}


