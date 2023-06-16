#include <stdio.h>

int main(){
	int a1,a2,a3,a4,l,s;
	printf("Enter four integers: ");
	scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
	
	l=a1;
	s=a1;
	
	if (a2>l)
		l=a2;
	else if (a2<s)
		s=a2;
		
	if (a3>l)
		l=a3;
	else if (a3<s)
		s=a3;
		
	if (a4>l)
		l=a4;
	else if (a4<s)
		s=a4;			

	
	printf("largest: %d\n",l);
	printf("smallest: %d\n",s);
	
	return 0;
}
