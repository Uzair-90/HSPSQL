#include<stdio.h>
#include<ctype.h>


int main()
{
  int matrix[5][5];
  printf("Enter the numbers of array: ");
  for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
          scanf("%d",&matrix[i][j]);
      }
  }
  
  int temp = 0;
  int temp2 = 0;
  int row_sum[5];
  int col_sum[5];
  
  for(int i = 0; i < 5; i++){
      temp = 0;
      temp2 = 0;
      for(int j = 0; j < 5; j++){
          temp+=matrix[i][j];
          temp2+=matrix[j][i];
      }
      row_sum[i] = temp;
      col_sum[i] = temp2;
      
      printf("Row sum:  %d\t",row_sum[i]);
      printf("Col sum:  %d\t",col_sum[i]);
  }
 
    return 0;
}
