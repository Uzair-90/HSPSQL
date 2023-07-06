#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5


bool straight, flush, four, three;
int pairs;

void read_cards(int hand[5][2]);
void analyze_hand(int hand[5][2]);
void print_result(void);
bool check_for_duplicate_card(int rank, int suit, int hand[5][2], int cards_read);

int main(void)
{
  int hand[5][2];

  for (;;) {
    read_cards(hand);
    analyze_hand(hand);
    print_result();
  }
}

void read_cards(int hand[5][2])
{
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card;
  int cards_read = 0;

  while (cards_read < NUM_CARDS) {
    bad_card = false;

    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default:            bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default:            bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = true;

    if (bad_card)
      printf("Bad card; ignored.\n");
    else if (check_for_duplicate_card(rank, suit, hand, cards_read))
      printf("Duplicate card; ignored.\n");
    else {
      hand[cards_read][0] = rank;
      hand[cards_read][1] = suit;
      cards_read++;
    }
  }
}

bool check_for_duplicate_card(int rank, int suit, int hand[5][2], int cards_read)
{
    int i;
    for (i = 0; i < cards_read; i++)
        if (hand[i][0] == rank && hand[i][1] == suit) 
            return true;

    return false;
}

void analyze_hand(int hand[5][2])
{
  int num_consec = 0;
  int card, rank;

  straight = false;
  flush = false;
  four = false;
  three = false;
  pairs = 0;

  int i, j, smallest, temp_suit, temp_rank;
  for (i = 0; i < NUM_CARDS; i++) {
      smallest = i;

      for (j = i+1; j < NUM_CARDS; j++) {
        if (hand[j][0] < hand[smallest][0])
            smallest = j;
      }

      temp_rank = hand[i][0];
      temp_suit = hand[i][1];
      hand[i][0] = hand[smallest][0];
      hand[i][1] = hand[smallest][1];
      hand[smallest][0] = temp_rank;
      hand[smallest][1] = temp_suit;
  }

  for (card = 1; card < NUM_CARDS; card++) {
    if (hand[card][1] != hand[0][1])
        break;

    if (card == NUM_CARDS - 1)
        flush = true;
  }

  for (card = 1; card < NUM_CARDS; card++) {
      if (hand[card][0] - hand[card-1][0] != 1)
          break;

      if (card == NUM_CARDS - 1)
        straight = true;
  }

  int matches;
  for (i = 0; i < NUM_CARDS; i++) {
      matches = 0;
      for (j = i + 1; j < NUM_CARDS; j++) {
          if (hand[j][0] == hand[i][0])
              matches++;
      }

      switch(matches) {
          case 1: pairs++;
                  break;
          case 2: three = true;
                  break;
          case 3: four = true;
                  break;
      }
  }
  
}

void print_result(void)
{
  if (straight && flush) printf("Straight flush");
  else if (four)         printf("Four of a kind");
  else if (three &&
           pairs == 1)   printf("Full house");
  else if (flush)        printf("Flush");
  else if (straight)     printf("Straight");
  else if (three)        printf("Three of a kind");
  else if (pairs == 2)   printf("Two pairs");
  else if (pairs == 1)   printf("Pair");
  else                   printf("High card");

  printf("\n\n");
}
