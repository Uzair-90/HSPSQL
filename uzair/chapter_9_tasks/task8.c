#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return (rand() % 6) + 1;
}

int playCraps() {
    int point = 0;
    int sum = rollDice() + rollDice();
    
    printf("You rolled: %d\n", sum);
    
    if (sum == 7 || sum == 11) {
        printf("You win!\n");
        return 1;
    }
    else if (sum == 2 || sum == 3 || sum == 12) {
        printf("You lose!\n");
        return 0;
    }
    else {
        point = sum;
        printf("Point is set to %d\n", point);
    }
    
    while (1) {
        sum = rollDice() + rollDice();
        printf("You rolled: %d\n", sum);
        
        if (sum == point) {
            printf("You win!\n");
            return 1;
        }
        else if (sum == 7) {
            printf("You lose!\n");
            return 0;
        }
    }
}

int main() {
    srand(time(0));
    
    printf("--- Welcome to the game of Craps ---\n");
    
    char choice;
    do {
        printf("\nPress Enter to play...");
        getchar();
        
        int result = playCraps();
        
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &choice);
        
        getchar(); // clear the newline character from the input buffer
        
    } while (choice == 'y' || choice == 'Y');
    
    printf("\nThank you for playing Craps!\n");
    
    return 0;
}

