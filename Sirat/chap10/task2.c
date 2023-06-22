#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define num_ranks 13
#define num_suits 4
#define num_cards 5

bool straight,flush,four,three;
int pairs;

void read_cards(int num_in_rank[], int num_in_suit[]);
void analyze_hand(const int num_in_rank[], const int num_in_suit[]);
void print_result(void);

int main(void) {
    int num_in_rank[num_ranks] = {0};
    int num_in_suit[num_suits] = {0};

    for (;;) {
        read_cards(num_in_rank, num_in_suit);
        analyze_hand(num_in_rank, num_in_suit);
        print_result();
    }

    return 0;
}

void read_cards(int num_in_rank[], int num_in_suit[]) {
    bool card_exists[num_ranks][num_suits];
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card;
    int cards_read = 0;

    for (rank = 0; rank < num_ranks; rank++) {
        num_in_rank[rank] = 0;
        for (suit = 0; suit < num_suits; suit++)
            card_exists[rank][suit] = false;
    }

    for (suit = 0; suit < num_suits; suit++)
        num_in_suit[suit] = 0;

    while (cards_read < num_cards) {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':
                exit(EXIT_SUCCESS);

            case '2':
                rank = 0;
                break;

            case '3':
                rank = 1;
                break;

            case '4':
                rank = 2;
                break;

            case '5':
                rank = 3;
                break;

            case '6':
                rank = 4;
                break;

            case '7':
                rank = 5;
                break;

            case '8':
                rank = 6;
                break;

            case '9':
                rank = 7;
                break;

            case 't':
            case 'T':
                rank = 8;
                break;

            case 'j':
            case 'J':
                rank = 9;
                break;

            case 'q':
            case 'Q':
                rank = 10;
                break;

            case 'k':
            case 'K':
                rank = 11;
                break;

            case 'a':
            case 'A':
                rank = 12;
                break;

            default:
                bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c':
            case 'C':
                suit = 0;
                break;
                
            case 'd':
            case 'D':
                suit = 1;
                break;

            case 'h':
            case 'H':
                suit = 2;
                break;

            case 's':
            case 'S':
                suit = 3;
                break;    

            default:
                bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ')
                bad_card = true;

        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (card_exists[rank][suit])
            printf("Duplicate card; ignored. \n");
        else {
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exists[rank][suit] = true;
            cards_read++;
        }
    }
}

void analyze_hand(const int num_in_rank[], const int num_in_suit[]) {
    int num_consec = 0;
    int rank, suit;
    bool straight = false;
    bool flush = false;
    bool four = false;
    bool three = false;
    int pairs = 0;

    for (suit = 0; suit < num_suits; suit++) {
        if (num_in_suit[suit] == num_cards) {
            flush = true;
            break;
        }
    }

    rank = 0;
    while (num_in_rank[rank] == 0)
        rank++;

    for (; rank < num_ranks && num_in_rank[rank] > 0; rank++)
        num_consec++;

    if (num_consec == num_cards)
        straight = true;


    for (rank = 0; rank < num_ranks; rank++) {
        if (num_in_rank[rank] == 4)
            four = true;
        if (num_in_rank[rank] == 3)
            three = true;
        if (num_in_rank[rank] == 2)
            pairs++;
    }

    straight = straight;
    flush = flush;
    four = four;
    three = three;
    pairs = pairs;
}

void print_result(void) {
    if (straight && flush)
        printf("Straight flush\n");
    else if (four)
        printf("Four of a kind\n");
    else if (three && pairs == 1)
        printf("Full house\n");
    else if (flush)
        printf("Flush\n");
    else if (straight)
        printf("Straight\n");
    else if (three)
        printf("Three of a kind\n");
    else if (pairs == 2)
        printf("Two pairs\n");
    else if (pairs == 1)
        printf("One pair\n");
    else
        printf("High card\n");
}


