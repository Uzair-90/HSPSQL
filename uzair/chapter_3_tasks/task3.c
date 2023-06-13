#include <stdio.h>

int main()
{
    int gs1_prefix = 0;
    int group_identfier = 0;
    int publisher_code = 0;
    int item_number = 0;
    int check_digit = 0;
    
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d",&gs1_prefix,&group_identfier,&publisher_code,&item_number,&check_digit);
    
    printf("GS1 Prefix: %d\n",gs1_prefix);
    printf("Group Identifier: %d\n",group_identfier);
    printf("Publisher code: %d\n",publisher_code);
    printf("Item number: %d\n",item_number);
    printf("Check digit: %d\n",check_digit);

    return 0;
}

