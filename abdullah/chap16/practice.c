#include<stdio.h>

struct student{
  int reg_num;
  int sem;
  long ph_num;
};

struct student details[100];

void get_details(){
    for(int i = 0; i < 5; i++){
        
        printf("Enter student %d reg_num: ",i+1);
        scanf("%d",&details[i].reg_num);
        printf("Enter student %d semeter: ",i+1);
        scanf("%d",&details[i].sem);
        printf("Enter student %d phone number: ",i+1);
        scanf("%ld",&details[i].ph_num);
    }
}

void display_details(){
    for(int i = 0; i < 5; i++){
        printf("student %d reg_num is: %d\n",i+1,details[i].reg_num);
        printf("student %d semeter is: %d\n",i+1,details[i].sem);
        printf("student %d phone number is: %d\n",i+1,details[i].reg_num);
    }
}



int main(){
    get_details();
    display_details();
}
