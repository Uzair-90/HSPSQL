#include <stdio.h>

struct date {
    int m;
    int d;
    int y;
};

int main() {
    struct date f, s;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &f.m, &f.d, &f.y);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &s.m, &s.d, &s.y);

	//
	if (f.y>s.y)
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",s.m,s.d,s.y,f.d,f.d,f.y);
	
	else if (f.y<s.y)
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",f.m,f.d,f.y,s.m,s.d,s.y);	
	
	else if (f.y==s.y && f.m>s.m)
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",s.m,s.d,s.y,f.m,f.d,f.y);
	
	else if (f.y==s.y && f.m<s.m)
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",f.m,f.d,f.y,s.m,s.d,s.y);
		
	else if (f.y==s.y && f.m==s.m && f.d>s.d)	
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",s.d,s.d,s.y,f.m,f.d,f.y);
		
	else if (f.y==s.y && f.m==s.m && f.d<s.d)	
		printf("%.2d/%.2d/%.2d is earlier than %.2d/%.2d/%.2d",f.m,f.d,f.y,s.m,s.d,s.y);
		
		

    return 0;
}

