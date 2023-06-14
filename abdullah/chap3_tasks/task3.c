
#include <stdio.h>

int main()
{
   int ISBN=0;
   int GS1_prefix=0;
   int group_indentifier=0;
   int publisher_code=0;
   int Item_number=0;
   int check_digit=0;
   
   printf("Enter ISBN: ");
   scanf("%d-%d-%d-%d-%d",&GS1_prefix,&group_indentifier,&publisher_code,&Item_number,&check_digit);
   printf("GS1 prefix: %d\n",GS1_prefix);
   printf("group indentifier:%d \n",group_indentifier);
   printf("publisher code:%d \n",publisher_code);
   printf("item number: %d\n",Item_number);
   printf("check digit: %d\n",check_digit);
   

    return 0;
}
