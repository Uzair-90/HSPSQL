#include <stdio.h>

int main(){
	int h,m;
	char s;
	
	printf("Enter a 12-hour time: ");
	scanf("%d:%d %c",&h,&m,&s);
	
	if (h==12&&s=='A')
    {
        h=0;
    }
    else if (h<12&&s=='P')
    {
        h+=12;
    }

    printf("Equivalent 24-hour time: %02d:%02d\n",h,m);

		return 0;
	}
	

