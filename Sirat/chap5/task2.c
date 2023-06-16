#include <stdio.h>

int main(){
	
	int h,m;
	printf("Enter a 24-hour time: ");
	scanf("%2d:%2d",&h,&m);
	
	if (h<=11 && h>=0)
		printf("Equivalent 12-hour time: %.2d:%.2d AM",h,m);
		
	else if (h==12)
		printf("Equivalent 12-hour time: %.2d:%.2d PM",h,m);	
		
	else if (h>=13 && h<=23) {
		h=h-12;
		printf("Equivalent 12-hour time: %.2d:%.2d PM",h,m);	
	}	
	
	else if (h==24) {
		h=0;
		printf("Equivalent 12-hour time: %.2d:%.2d AM",h,m);
	}
	
	return 0;
}
