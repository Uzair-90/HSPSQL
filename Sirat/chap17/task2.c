#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define IMAX_PARTS 10

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;

};

int read_line(char str[],int n)
{int ch,i=0;
while(isspace(ch=getchar()))
;
while(ch!='\n' && ch !=EOF){
	if (i<n)
	str[i++]=ch;
	ch=getchar();
}
str[i]='\0';
return i;
}

int num_parts = 0;
int MAX_PARTS = IMAX_PARTS;
struct part *inventory;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void sort(struct part inventory[], int num_parts);
int main() {
	inventory =malloc(MAX_PARTS*sizeof(struct part));
	
	if(inventory ==NULL){
		printf("FAILED ALLOCATION.\n");
		return 1;
	}
  
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;

        switch (code) {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'q':
        	free(inventory);
            return 0;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(int number) {
    int i;
	for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number)
            return i;
    }
    return -1;
}

void insert(void) {
    int part_number;

    if (num_parts == MAX_PARTS) {
        MAX_PARTS *= 2;
        inventory = realloc(inventory, MAX_PARTS * sizeof(struct part));

        if (inventory == NULL) {
            printf("FAILED ALLOCATION.\n");
            exit(1);
        }
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;

    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);

    (num_parts)++;
}

void search(void) {
    int number, i;
    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else {
        printf("Part not found.\n");
    }
}

void update(void) {
    int number, i, change;
    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}


void sort(struct part inventory[], int num_parts){
    int i;
    if (num_parts <= 1)
        return;

    int maxIndex = 0;
    for (i = 1; i < num_parts; i++) {
        if (inventory[i].number > inventory[maxIndex].number)
            maxIndex = i;
    }

    struct part temp = inventory[maxIndex];
    inventory[maxIndex] = inventory[num_parts - 1];
    inventory[num_parts - 1] = temp;

    sort(inventory, num_parts - 1);
}

void print(void) {
	struct part sorted_inventory[MAX_PARTS];
    int i;
    for (i = 0; i < num_parts; i++) {
        sorted_inventory[i] = inventory[i];
    }

    sort(sorted_inventory,num_parts);

    printf("Part Number    Part Name                Quantity on Hand\n");
    for (i = 0; i < num_parts; i++) {
        printf("%-15d%-25s%d\n",sorted_inventory[i].number, sorted_inventory[i].name, sorted_inventory[i].on_hand);
    }
}
