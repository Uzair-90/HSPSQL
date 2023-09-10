x#include <stdio.h>

//1.

int main(){
	int y=0;
	int m=0;
	int d=0;
	
	printf("enter a date (mm/dd/yyyy): ");
	scanf("%d/%d/%d",&m,&d,&y);
	
	printf("you entered the date %.4d%.2d%.2d",y,m,d);
	
	return 0;
}


//2.

int main(){
	
	int item=0;
	float p=0;
	int y=0;
	int m=0;
	int d=0;
	
	printf("Enter item number: ");
	scanf("%d",&item);
	
	printf("Enter unit price: ");
	scanf("%f",&p);
	
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d",&m,&d,&y);
	
	printf("item\tunit\tpurchase\n");
	printf("\tprice\tdate\n");
	printf("%d\t%.2f\t%d/%d/%d",item,p,m,d,y);
	return 0;	
}


//3.

int main(){
	
	int p=0;
	int i=0;
	int c=0;
	int n=0;
	int d=0;
	
	printf("enter ISBN: ");
	scanf("%d-%d-%d-%d-%d",&p,&i,&c,&n,&d);
	
	printf("GSI prefix: %d\n",p);
	printf("Group identifier: %d\n",i);
	printf("publisher code: %d\n",c);
	printf("item number: %d\n",n);
	printf("check digit: %d\n",d);
	
	return 0;

}


//4.

int main(){
	int f=0;
	int m=0;
	int l=0;
	
	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf("(%d)%d-%d",&f,&m,&l);
	
	printf("you entered %d.%d.%d",f,m,l);
	
	return 0;

}


//6.

int main(){
	int n1=0;
	int n2=0;
	int d1=0;
	int d2=0;
	
	printf("Enter two fractions separated by a plus sign : ");
	scanf("%d/%d+%d/%d",&n1,&d1,&n2,&d2);
	
	printf("sum is : %d/%d",n1*d2+n2*d1,d1*d2);
	return 0;
}




