#include <stdio.h>

int main(){
	int fm,fd,fy,sm,sd,sy;
	
	printf("Enter first date (mm/dd/yy): ");
	scanf("%d/%d/%d",&fm,&fd,&fy);
	
	printf("Enter second date (mm/dd/yy): ");
	scanf("%d/%d/%d",&sm,&sd,&sy);
	
	if (fy>sy)
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",sm,sd,sy,fm,fd,fy);
	
	else if (fy<sy)
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",fm,fd,fy,sm,sd,sy);	
	
	else if (fy==sy && fm>sm)
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",sm,sd,sy,fm,fd,fy);
	
	else if (fy==sy && fm<sm)
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",fm,fd,fy,sm,sd,sy);
		
	else if (fy==sy && fm==sm && fd>sd)	
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",sm,sd,sy,fm,fd,fy);
		
	else if (fy==sy && fm==sm && fd<sd)	
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",fm,fd,fy,sm,sd,sy);
		
	return 0;			
		
	
}
