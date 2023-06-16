#include <stdio.h>

int main(){
	
	float loan=0;
	float rate=0;
	float pay=0;
	int n,i;
	
	printf("Enter amount of loan: ");
	scanf("%f",&loan);
	printf("Enter interest rate: ");
	scanf("%f",&rate);
	printf("Enter monthly payment: ");
	scanf("%f",&pay);
	printf("Enter number of payments: ");
	scanf("%d,",&n);
	
	
	float monthly_rate=(rate/100)/12;
	loan=loan-pay+(loan*monthly_rate); 
	
	for(i=1;i<=n;i++){
	
	printf("Balance remaining after %d payment: %.2f\n",i,loan);
	loan=loan-pay+(loan*monthly_rate);
	}
	
	return 0;
	
}

