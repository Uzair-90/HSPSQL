#include<stdio.h>

int main(){
    int m1,d1,y1,m2,d2,y2;
    
    printf("Enter the first date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&m1,&d1,&y1);
    
    printf("Enter the second date (mm/dd/yyyy): ");
    scanf("%d/%d/%d",&m2,&d2,&y2);
    
    if(d1 < d2 && m1==m2 && y1 == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m1,d1,y1,m2,d2,y2);
    } else if (d1 > d2 && m1==m2 && y1 == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,m1,d1,y1);
    } else if (d1 == d2 && m1<m2 && y1 == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m1,d1,y1,m2,d2,y2);
    } else if (d1 == d2 && m1>m2 && y1 == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m1,d1,y1,m2,d2,y2);
    } else if (d1 == d2 && m1==m2 && y1 > y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,m1,d1,y1);
    } else if (d1 == d2 && m1==m2 && y1 < y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m1,d1,y1,m2,d2,y2);
    } else if (d1 < d2 && m1 < m2 && y1 < y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m1,d1,y1,m2,d2,y2);
    } else if (d1 > d2 && m1 > m2 && y1 > y2 ){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,m1,d1,y1);
    } else if (d1 < d2 && m1 > m2 && y1 < y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m1,d1,y1,m2,d2,y2);
    } else if (d1 > d2 && m1 < m2 && y1 > y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,m1,d1,y1);
    } else if (d1 > d2 && m1 < m2 && y1 == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m1,d1,y1,m2,d2,y2);   
    } else if (d1 < d2 && m1 > m2 && y1 == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,m1,d1,y1);
    } else if (d1 < d2 && m1 < m2 && y1 == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m1,d1,y1,m2,d2,y2);
    } else if (d1 > d2 && m1 > m2 && y1 == y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,m1,d1,y1);
    } else if (d1 < d2 && m1 < m2 && y1 > y2){
        printf("%d/%d/%d is earlier than %d/%d/%d\n",m2,d2,y2,m1,d1,y1);
    }
    
    return 0;
}
