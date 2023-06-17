

#include <stdio.h>

int main()
{
 int month=0;
 int days=0;
 int years=0;
 
 int m2=0;
 int d2=0;
 int y2=0;
 
 printf("Enter the first date (mm/dd/yyyy): ");
 scanf("%d/%d/%d",&month,&days,&years);
 
 printf("Enter the second date (mm/dd/yyyy): ");
 scanf("%d/%d/%d",&m2,&d2,&y2);
 
  if(days < d2 && month==m2 && years == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",month,days,years,m2,d2,y2);
    } else if (days > d2 && month==m2 && years == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,month,days,years);
    } else if (days == d2 && month<m2 && years == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",month,days,years,m2,d2,y2);
    } else if (days == d2 && month>m2 && years == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",month,days,years,m2,d2,y2);
    } else if (days == d2 && month==m2 && years > y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,month,days,years);
    } else if (days == d2 && month==m2 && years < y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",month,days,years,m2,d2,y2);
    } else if (days < d2 && month < m2 && years < y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",month,days,years,m2,d2,y2);
    } else if (days > d2 && month > m2 && years > y2 ){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,month,days,years);
    } else if (days < d2 && month > m2 && years< y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",month,days,years,m2,d2,y2);
    } else if (days > d2 && month < m2 && years> y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,month,days,years);
    } else if (days > d2 && month < m2 && years == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",month,days,years,m2,d2,y2);   
    } else if (days < d2 && month > m2 && years== y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,month,days,years);
    } else if (days < d2 && month < m2 && years == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",month,days,years,m2,d2,y2);
    } else if (days > d2 && month> m2 && years == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,month,days,years);
    } else if (days < d2 && month < m2 && years > y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,month,days,years);
    }
    return 0;
}
