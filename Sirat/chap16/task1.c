#include <stdio.h>

struct dialing_code{
	char *country;
	int code;
};


int main(){
	
	const struct dialing_code dcode[]={{"argentina",54},{"bangladesh",880},{"brazil",55},
									{"burma",95},{"china",86},{"colombia",57},
									{"congo, dem.rep.of",243},{"egypt",20},{"ethiopia",251},
									{"france",33},{"germany",49},{"india",91},
									{"indonesia",62},{"iran",98},{"italy",39},
									{"japan",81},{"pakistan",92},{"philippines",63},
									{"poland",48},{"russia",7},{"south africa",27},
									{"south korea",82},{"spain",34},{"sudan",249},
									{"thailand",66},{"turkey",90},{"ukraine",380},
									{"united kingdom",44},{"united states",1},{"vietnam",84}};
									
				
	int c,i;								
	printf("enter an international dialing code: ");
	scanf("%d",&c);	
	
	for(i=0;i<33;i++){		
		if (dcode[i].code==c){
		printf("country: %s",dcode[i].country);
		break;
	}
	}	
	
	if(i==33)
	printf("\n!!ERROR!!");				
	
	return 0;
}
