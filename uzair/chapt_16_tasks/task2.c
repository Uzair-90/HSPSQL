#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define max_parts 100
#define max_len 50

typedef struct 
{
    int number;
    char name[max_len+1];
    int on_hand;
} Part;

int partition(Part arr[], int low, int high);
void quickSort(Part arr[], int low, int high);
void swap(Part *x, Part *y);

void swap(Part *x, Part *y){
	Part temp = *x;
	*x = *y;
	*y = temp;
}


int partition(Part arr[], int low, int high)
{
	// Choosing the pivot
	int pivot = arr[high].number;

	// Index of smaller element and indicates
	// the right position of pivot found so far
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {

		// If current element is smaller than the pivot
		if (arr[j].number < pivot) {

			// Increment index of smaller element
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}



void quickSort(Part arr[], int low, int high)
{
	if (low < high) {

		// pi is partitioning index, arr[p]
		// is now at right place
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void read_line(char str[],int len){
    int ch, i = 0;

    while((ch = getchar())!= '\n' && ch != EOF){
        if(i == len){
            break;
        }
        str[i] = ch;
        i++;
    }
    str[i+1] = '\0';
}


Part inventory[max_parts];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);


int main(void){
    char code;
    for(;;){
        printf("Enter operation code: ");
        scanf("%c",&code);
        while(getchar() !='\n')
        ;
        switch (code)
        {
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
            return 0;
        default:
            printf("Illelgal operation!\n");
        }
        printf("\n");
    }
}

int find_part(int number){
    int i;

    for(i = 0; i < num_parts;i++){
        if(inventory[i].number == number){
            return i;
        }
    }
    return -1;
}

void insert(void){
    int part_number;
    if(num_parts == max_parts){
        printf("Database is full. Can't add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d",&part_number);

    if(find_part(part_number) >=0){
        printf("Part already exists.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name,max_len);
    printf("Enter quantity on hard: ");
    scanf("%d",&inventory[part_number].on_hand);
    num_parts++;
}

void search(void){
    int i, number;
    printf("Enter part number: ");
    scanf("%d",&number);
    i = find_part(number);
    if(i >= 0){
        printf("Part name: %s\n",inventory[i].name);
        printf("Quantity on hand: %d\n",inventory[i].on_hand);
    }else{
        printf("Part doesn't exist.\n");
    }
}

void update(void){
    int i, number, change;
    printf("Enter part number: ");
    scanf("%d",&number);
    i = find_part(number);
    if(i>=0){
        printf("Enter change in quantity on hand: ");
        scanf("%d",&change);
        inventory[i].on_hand+=change;
    } else{
        printf("Part doesn't exists.\n");
        return;

    }
}

void print(void){
    quickSort(inventory,0,num_parts-1);
    int i;
    printf("Part Number     Part Name       Quantity on Hand\n");
    for(i = 0; i < num_parts; i++){
        printf("%7d     %-25s   %d\n",inventory[i].number,inventory[i].name,inventory[i].on_hand);
    }
}


