#include <stdio.h>

void find_closest_flight(int desired_time,int *departure,int *arrival){
	
	int d1=(8*60);
	int d2=(9*60)+43;
	int d3=(11*60)+19;
	int d4=(12*60)+47;
	int d5=(14*60);
	int d6=(15*60)+45;
	int d7=(19*60);
	int d8=(21*60)+45;
	
	int diff1=abs(d1-desired_time);
	int diff2=abs(d2-desired_time);
	int diff3=abs(d3-desired_time);
	int diff4=abs(d4-desired_time);
	int diff5=abs(d5-desired_time);
	int diff6=abs(d6-desired_time);
	int diff7=abs(d7-desired_time);
	int diff8=abs(d8-desired_time);	
	
	int s=diff1;
	
	if (diff2<s)
		s=diff2;
		
	if (diff3<s)
		s=diff3;

	if (diff4<s)
		s=diff4;
		
	if (diff5<s)
		s=diff5;
		
	if (diff6<s)
		s=diff6;
		
	if (diff7<s)
		s=diff7;
		
	if (diff8<s)
		s=diff8;
		
		
	if (s==diff1){
		*departure=d1;
		*arrival=(10*60)+16;
	}
		
	else if (s==diff2){
		*departure=d2;
		*arrival=(11*60)+52;
	}
		
		
	else if (s==diff3){
		*departure=d3;
		*arrival=(13*60)+31;
	}
		
	else if (s==diff4){
		*departure=d4;
		*arrival=(15*60);
	}
		
	else if (s==diff5){
		*departure=d5;
		*arrival=(16*60)+8;
	}
		
	else if (s==diff6){
		*departure=d6;
		*arrival=(17*60)+55;
	}						
		
	else if (s==diff7){
		*departure=d7;
		*arrival=(21*60)+20;
	}	
		
	else if (s==diff8){
		*departure=d8;
		*arrival=(23*60)+58;
	}	
			
	
}

int main(){
	
	int h,m,d,a;
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d",&h,&m);
	
	int t = h * 60 + m;
    
	find_closest_flight(t,&d,&a);
	
	//converting mins to hours
	
	int dh=d/60;
	int dm=d%60;
	int ah=a/60;
	int am=a%60;
	
	//converting 24h time to 12h
	
	if (dh>12)
		dh=dh-12;
		
	else if(dh==24)
		dh=00;
		
	if (ah>12)
		ah=ah-12;
		
	else if(ah==24)
		ah=00;		
			
			
	printf("Closest departure time is %02d:%02d, arriving at %02d:%02d\n", dh, dm, ah, am);

	
	
	
		
}
