#include <stdio.h>

#define max_digits 10

int segments[max_digits][7] = {{1,1,1,1,1,1,0},
									{0,1,1,0,0,0,0},
									{1,1,0,1,1,0,1},
									{1,1,1,1,0,0,1},
									{0,1,1,0,0,1,1},
									{1,0,1,1,0,1,1},
									{1,0,1,1,1,1,1},
									{1,1,1,0,0,0,0},
									{1,1,1,1,1,1,1},
									{1,1,1,1,0,1,1}};
									
char digits [4]	[max_digits*4];								
 
void clear_digits_array(void){
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<max_digits*4;j++){
			digits[i][j]=' ';
		}
	}
}

void process_digit(int digit, int position){
	 int i;
    for (i= 0; i< 7; i++) {
        if (segments[digit][i]) {
            switch (i) {
                case 0:
                    digits[0][position * 4 + 1] = '_';
                    break;
                case 1:
                case 2:
                    digits[1][position * 4 + i] = '|';
                    break;
                case 3:
                    digits[2][position * 4 + i - 1] = '|';
                    break;
                case 4:
                    digits[2][position * 4 + i] = '_';
                    break;
                case 5:
                case 6:
                    digits[3][position * 4 + i - 2] = '|';
                    break;
            }
        }
    }
	
	
}
void print_digits_array(void) {
    int i, j;
    for (i = 0; i< 4; i++) {
        for (j = 0; j< max_digits * 4; j++) {
            printf("%c", digits[i][j]);
        }
		printf("\n");
    }
}

int main(void) {
    char input[max_digits + 1];
    int position = 0;

    printf("Enter a number: ");
    scanf("%s", input);

    clear_digits_array();

    while (input[position] != '\0' && position < max_digits) {
        if (input[position] >= '0' && input[position] <= '9') {
            int digit = input[position] - '0';
            process_digit(digit, position);
            
        }
        position++;
        
    }

    print_digits_array();

    return 0;
}
