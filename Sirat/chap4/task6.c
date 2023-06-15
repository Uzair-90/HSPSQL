#include <stdio.h>

int main(){
	int d,i1,i2,i3,i4,i5,j1,j2,j3,j4,j5,j6,fs,ss,t;
	printf("Enter the first 12 digits of a EAN: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&d,&i1,&i2,&i3,&i4,&i5,&j1,&j2,&j3,&j4,&j5,&j6);
	
	fs=i1+i3+i5+j2+j4+j6;
	ss=d+i2+i4+j1+j3+j5;

	t=3*fs+ss;
	
	printf("Check digit: %d",9-((t-1)%10));
	
	return 0;
}
