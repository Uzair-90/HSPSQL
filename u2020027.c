#include<stdio.h>

int main(){

	char name[50];
	name = "Abdullah Khan";
	printf("My name is: %s",name);
	int array[5];
	array = {20,30,50,10,5};
	int max = 0;
	for(int i = 0; i < 5; i++){
		if(array[i] > max){
			max = array[i];
		}}
	printf("Max is: %d",max);
	int min = array[0];

	for( int i = 0; i < 5; i++){ if(min < array[i]) { min = array[i];}}
	printf("The min is: %d",min);
	
	printf("I am just testing merge conflicts");


	return 0;
}
