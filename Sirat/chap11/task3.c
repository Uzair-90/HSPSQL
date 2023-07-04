#include <stdio.h>

void reduce (int num,int den,int *red_num,int *red_den){
	
	int i=0;
	
		if(num<den)
		i=num;
	else 
		i=den;
		
		
	while(i>1){
		if(num%i==0 && den%i==0)
			break;
		i--;	
	}
	
	*red_num=num/i;
	*red_den=den/i;
	
	
}

int main(){
	
	int n,d,rn,rd;
	
	printf("Enter a fraction: ");
	scanf("%d/%d",&n,&d);
	
	reduce(n,d,&rn,&rd);	
	
	printf("in lowest term: %d/%d",rn,rd);
	
}
