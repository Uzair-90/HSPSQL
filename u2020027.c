#include<stdio.h>

int main(){

	char name[50] = "Abdullah Khan";
	printf("My name is: %s\n",name);
	int array[] = {20,30,50,10,5};
	int max = 0;
	for(int i = 0; i < 5; i++){
		if(array[i] > max){
			max = array[i];
		}}
	printf("Max is: %d\n",max);
	int min = array[0];

	for( int i = 0; i < 5; i++){ if(min > array[i]) { min = array[i];}}
	printf("The min is: %d\n",min);


	return 0;
}
