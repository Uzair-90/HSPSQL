#include <stdio.h>

int main(){
	float n,t;
	
	printf("Enter the amount of taxable income: ");
	scanf("%f",&n);
	
	if (n<=750){
		t=0.01*n;
		printf("tax due: %.2f",t);
	}
	
	else if (n>750 && n<=2250){
		t=7.50+(0.02*(n-750));
		printf("tax due: %.2f",t);
	}	
	
	else if (n>2250 && n<=3750){
		t=37.50+(0.03*(n-2250));
		printf("tax due: %.2f",t);
	}	
	
	else if (n>3750 && n<=5250){
		t=82.50+(0.04*(n-3750));
		printf("tax due: %.2f",t);
	}	
	
	else if (n>5250 && n<=7000){
		t=142.50+(0.05*(n-5250));
		printf("tax due: %.2f",t);
	}	
	
	else{
		t=230.00+(0.06*(n-7000));
		printf("tax due: %.2f",t);
	}	

	return 0;
	
	
}
