#include <stdio.h>

//1.

int main(){
	printf("        *\n");
	printf("       *\n");
	printf("      *\n");
	printf(" *   *\n");
	printf("  * *\n");
	printf("   *\n");
	return 0;
}



//2.

int main(){
	int r=10;
	int pi=3.14;
	float v=(4.0f/3.0f)*pi*(r*r*r);
	printf("Volume: %f",v);
	
	return 0;
}


//3.

int main(){
	int r=0;
	int pi=3.14;
	printf("enter radius= ");
	scanf("%d",&r);
	float v=(4.0f/3.0f)*pi*(r*r*r);
	printf("Volume: %f",v);
	
	return 0;
	
}


//4.

int main(){
	float a=0;
	printf("Enter an amount: ");
	scanf("%f",&a);
	printf("with tax added: $%f",a+(0.05*a));
	return 0;
}


//5.

int main()
{
    float x=0;
    printf("Enter x= ");
    scanf("%f",&x);
    float p=3*(x*x*x*x*x)+2*(x*x*x*x)-5*(x*x*x)-(x*x)+7*x-6;
    printf("ploynomial value= %f\n",p);
    return 0;
    
}


//6.

int main()
{
    float x=0;
    printf("Enter x= ");
    scanf("%f",&x);
    float p=(((((3*x)+2)*x-5)*x-1)*x+7)*x-6;
    printf("ploynomial value= %f\n",p);
    return 0;  
}


//7.

int main(){
	int d=0;
	printf("Enter a dollar amount: ");
	scanf("%d",&d);
	int a=d/20;							//%20 bills
	printf("$20 bills: %d\n",a);
	int b=(d-(a*20))/10;				//$10 bills
	printf("$10 bills: %d\n",b);
	int c=(d-(a*20)-(b*10))/5;			//$5 bills
	printf("$5 bills: %d\n",c);
	int e=(d-(a*20)-(b*10)-(c*5));		//$1 bills
	printf("$1 bills: %d\n",e);
	
	return 0;
	
}


//8.
int main(){

	float loan=0;
	float rate=0;
	float pay=0;
	
	printf("Enter amount of loan: ");
	scanf("%f",&loan);
	printf("Enter interest rate: ");
	scanf("%f",&rate);
	printf("Enter monthly payment: ");
	scanf("%f",&pay);
	
	float monthly_rate=(rate/100)/12;
	loan=loan-pay+(loan*monthly_rate); 
	
	printf("Balance remaining after first payment: %.2f\n",loan);
	loan=loan-pay+(loan*monthly_rate);
	
	printf("Balance remaining after second payment: %.2f\n",loan);
	loan=loan-pay+(loan*monthly_rate);
	
	printf("Balance remaining after third payment: %.2f",loan);

	return 0;
	
}

