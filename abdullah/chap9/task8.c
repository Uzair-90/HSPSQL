#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#include<stdbool.h>

int roll_dice(){

    srand(time(NULL));

    int r = rand()%6;
    int r2 = rand()%6;

    return r+r2;
}

void play_game(){
    int num = roll_dice();
    int count = 0;
    bool array[12]={false};
    
    if(count == 0 && num == 7 || num == 11){
        printf("\n\tYou rolled %d on first try.\n",num);
        printf("\tYou Win!\n");
        return;
    }else if(count == 0 && num == 2 || num == 8 || num == 12){
        printf("\tOn first try you rolled %d: \n",num);
        printf("\tYou Lose!\n");
        return;
    }
    
    while(1){
        count++;
    
        int try2 = roll_dice();
    
        if(count > 0 && try2 == 7){
            printf("You roll 7 on second try.\n");
            printf("\tYou Lose!\n");
            break;
        }else{
        
            if(array[try2] == true){
                printf("You rolled %d again.\n",try2);
                printf("\tYou win!");
                break;
        }
            printf("\tYou rolled: %d\n",try2);
            printf("\tYour point is: %d\n",try2);
            array[try2] = true;
    }
}
    
}

int main(){
    char ch = 'y';
    while(ch != 'n'){
        play_game();
        printf("\nDo you want to play again? y/n: ");
        scanf("%c",&ch);
    };
    
    return 0;
}
