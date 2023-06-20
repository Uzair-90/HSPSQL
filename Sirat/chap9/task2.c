#include <stdio.h>

float tax(float n){
	
	float t;
	if (n<=750){
		t=0.01*n;
		return t;
	}
	
	else if (n>750 && n<=2250){
		t=7.50+(0.02*(n-750));
		return t;
	}	
	
	else if (n>2250 && n<=3750){
		t=37.50+(0.03*(n-2250));
		return t;
	}	
	
	else if (n>3750 && n<=5250){
		t=82.50+(0.04*(n-3750));
		return t;
	}	
	
	else if (n>5250 && n<=7000){
		t=142.50+(0.05*(n-5250));
		return t;
	}	
	
	else{
		t=230.00+(0.06*(n-7000));
		return t;
	}	

}


int main(){
	
	float a,s;
	
	printf("Enter the amount of taxable income: ");
	scanf("%f",&a);
	
	s =tax(a);
	
	printf("tax due: %.2f",s);
	
}
