#include <stdbool.h>
#include <stdio.h>

int main(){
	
	bool d_seen[10] = {false};
	int digit;
	long n;
	int r_digit[10];
    int r_count = 0;
    int i;
	
	printf("Enter a number: ");
	scanf("%ld", &n);
	
	while (n > 0){
		digit = n % 10;
		if (d_seen[digit]){
			r_digit[r_count] = digit;
            r_count++;
		}
		d_seen[digit] = true;
		n /= 10;	
	}
	
	if (r_count > 0){
	
		printf("repeat: ");
		for (i = 0; i < r_count; i++) {
            printf("%d ", r_digit[i]);
        }
    }
	else 
		printf("no repeat: ");	
		
	return 0;			
}

