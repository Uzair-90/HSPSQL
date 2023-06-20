#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int roll_dice(void){
	srand(time(NULL));
	
	int r1=(rand()%(6))+1;
	int r2=(rand()%(6))+1;
	
	return r1+r2;
	
}

bool play_game(void){
	int n=roll_dice();
	
	if(n==4 || n==5 || n==6 || n==8 ||n==9 || n==10){
		printf("you rolled %d\n",n);
		printf("your point is %d\n", n);
		
		int p =n;
		while(true){
			n=roll_dice();
			printf("you rolled %d\n",n);
			
			if(n==7)
				return false;
				
			else if (n==p)
				return true;
		}
		
	}
	
	else if(n==7 || n==11){
		printf("you rolled %d\n",n);
		return true;
	}	
	
	else if(n==2 ||n==3 || n==12){
		printf("you rolled %d\n",n);
		return false;
	}
	
	
}

int main() {
    char a = 'y';
    int w = 0;
    int l = 0;

    while (a != 'n') {
        bool s = play_game();

        if (s == true) {
            printf("You win!\n");
            w++;
        } else {
            printf("You lose!\n");
            l++;
        }

        printf("\n\nPlay again? ");
        getchar(); 
        scanf("%c", &a);
    }

    printf("Wins: %d Losses: %d\n", w, l);

    return 0;
}

