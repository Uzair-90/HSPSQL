#include <stdio.h>

void pay_amount(int d,int *twenties,int *tens,int *fives,int *ones){
		
	*twenties=d/20;							//%20 bills

	*tens=(d-(*twenties*20))/10;				//$10 bills

	*fives=(d-(*twenties*20)-(*tens*10))/5;			//$5 bills

	*ones=(d-(*twenties*20)-(*tens*10)-(*fives*5));		//$1 bills
	
}

int main(){
	
	int d=0;
	int t,ten,f,o;
	printf("Enter a dollar amount: ");
	scanf("%d",&d);
	
	pay_amount(d,&t,&ten,&f,&o);
	
	printf("$20 bills: %d\n",t);
	
	printf("$10 bills: %d\n",ten);

	printf("$5 bills: %d\n",f);
	
	printf("$1 bills: %d\n",o);
	
	return 0;
	
}
