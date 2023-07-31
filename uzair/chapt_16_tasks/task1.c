#include<stdio.h>
#include<string.h>
#define max_len 50

struct country_code
{
    char country_name[max_len+1];
    int code;
};

void search_country(const struct country_code x[], int size, int dial_code){
    if(dial_code == 0){
        return;
    }
    for(int i = 0; i < size; i++){
        if(x[i].code == dial_code){
            printf("The code belongs to %s\n",x[i].country_name);
            return;
        }
    }
    
        printf("Code %d doesn't exist in the database.\n",dial_code);
}


int main(){
    int dial_code = 1;
    int count = 32;
    const struct country_code ncodes[] = {
        {"Argentina", 54},{"Bangladesh", 880},{"Brazil",55},{"Burma (Myanmar)",95},{"China",86},{"Colombia",57},
        {"Congo",243},{"Egypt",20},{"Ehiopia",251},{"France",33},{"Germany",43},{"India",91},{"Indonesia",62},
        {"Iran",98},{"Italy",39},{"Japan",81},{"Mexico",52},{"Nigeria",234},{"Pakistan",92},{"Phillipines",63},
        {"Poland",48},{"Russia",7},{"South Africa",27},{"South Korea",82},{"Spain",34},{"Sudan",249},{"Thailand",66},
        {"Turkey",90},{"Ukraine",380},{"United Kingdom",44},{"United States",1},{"Vietnam",84}
    };

    while(dial_code != 0){
        printf("Enter a dial code to search and 0 to exit: ");
        scanf("%d",&dial_code);
        search_country(ncodes,count,dial_code);
    }

    return 0;
}