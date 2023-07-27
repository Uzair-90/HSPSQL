#include <stdio.h>

#define NAME_LEN 25
#define MAX_PARTS 100

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

int find_part(const struct part inventory[], int num_parts, int number);
void insert(struct part inventory[], int *num_parts);
void search(const struct part inventory[], int num_parts);
void update(struct part inventory[], int num_parts);
void print(const struct part inventory[], int num_parts);
void sort(struct part inventory[], int num_parts);

int main() {
    struct part inventory[MAX_PARTS];
    int num_parts = 0;
    char code;

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            ;

        switch (code) {
        case 'i':
            insert(inventory, &num_parts);
            break;
        case 's':
            search(inventory, num_parts);
            break;
        case 'u':
            update(inventory, num_parts);
            break;
        case 'p':
            print(inventory, num_parts);
            break;
        case 'q':
            return 0;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
}

int find_part(const struct part inventory[], int num_parts, int number) {
    int i;
	for (i = 0; i < num_parts; i++) {
        if (inventory[i].number == number)
            return i;
    }
    return -1;
}

void insert(struct part inventory[], int *num_parts) {
    int part_number;

    if (*num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_number);

    if (find_part(inventory, *num_parts, part_number) >= 0) {
        printf("Part already exists.\n");
        return;
    }

    inventory[*num_parts].number = part_number;

    printf("Enter part name: ");
    read_line(inventory[*num_parts].name, NAME_LEN);

    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[*num_parts].on_hand);

    (*num_parts)++;
}

void search(const struct part inventory[], int num_parts) {
    int number, i;
    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    } else {
        printf("Part not found.\n");
    }
}

void update(struct part inventory[], int num_parts) {
    int number, i, change;
    printf("Enter part number: ");
    scanf("%d", &number);

    i = find_part(inventory, num_parts, number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

void sort(struct part inventory[], int num_parts) {
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


void print(const struct part inventory[], int num_parts) {
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
