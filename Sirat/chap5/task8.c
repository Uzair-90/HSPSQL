#include <stdio.h>

int main(){
	int h,m;
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&h,&m);
	
	int t=(h*60)+m;
	int d1=(8*60)+0;
	int d2=(9*60)+43;
	int d3=(11*60)+19;
	int d4=(12*60)+47;
	int d5=(2*60)+0;
	int d6=(3*60)+45;
	int d7=(7*60)+0;
	int d8=(9*60)+45;
	
	int diff1=d1-t;
	int diff2=d2-t;
	int diff3=d3-t;
	int diff4=d4-t;
	int diff5=d5-t;
	int diff6=d6-t;
	int diff7=d7-t;
	int diff8=d8-t;	
	
	
	int s=diff1;
	
	if (diff2>s)
		s=diff2;
		
	if (diff3>s)
		s=diff3;

	if (diff4>s)
		s=diff4;
		
	if (diff5>s)
		s=diff5;
		
	if (diff6>s)
		s=diff6;
		
	if (diff7>s)
		s=diff7;
		
	if (diff8>s)
		s=diff8;	
		
	if (s==diff1)
		printf("closest departure time is 8:00 am, arriving at 10:16 am");
		
	else if (s==diff2)
		printf("closest departure time is 9:43 am, arriving at 11:52 am");
		
	else if (s==diff3)
		printf("closest departure time is 11:19 am, arriving at 1:31 pm");
		
	else if (s==diff4)
		printf("closest departure time is 12:47 pm, arriving at 3:00 pm");
		
	else if (s==diff5)
		printf("closest departure time is 2:00 pm, arriving at 4:08 pm");
		
	else if (s==diff6)
		printf("closest departure time is 3:45 pm, arriving at 5:55 pm");						
		
	else if (s==diff7)
		printf("closest departure time is 7:00 pm, arriving at 9:20 pm");	
		
	else if (s==diff8)
		printf("closest departure time is 9:45 pm, arriving at 11:58 pm");	
		
		return 0;					
}
