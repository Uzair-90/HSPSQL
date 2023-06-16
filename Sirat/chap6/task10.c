#include <stdio.h>

int main (){
	int y,m,d,sm,sd,sy;
	
	printf("Enter a date (mm/dd/yy): ");
	scanf("%d/%d/%d",&m,&d,&y);
	
	sm=m;
	sd=d;
	sy=y;
	
	
	while(y!=0 && m!=0 && d!=0){
		
		printf("Enter a date (mm/dd/yy): ");
		scanf("%d/%d/%d",&m,&d,&y);
		
		
		
		if(sy>y && y!=0){
			sy=y;
			sd=d;
			sm=m;
		}
		
		else if(sy==y && sm>m && y!=0){
			sy=y;
			sd=d;
			sm=m;
			
		}
		
		else if(sy==y && sm==m && sd>d && y!=0){
			sy=y;
			sd=d;
			sm=m;
			
		}
			
	}
	
	printf("%d/%d/%d is the earliest date",sm,sd,sy);

return 0;
	
}
