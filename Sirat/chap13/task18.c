#include <stdio.h>

int main(){
	
	int d, m, y;
	
	    char *mw[] = {
        "","january", "february", "March", "April", 
		"May", "June", "July", 
		"August", "september", "october","november","december"
    };
	
	printf("enter a date(mm/dd/yyyy): ");
	scanf("%2d/%2d/%4d", &m, &d, &y);
	
	printf("you entered the date %s %d,%d",mw[m],d,y);
	
}
