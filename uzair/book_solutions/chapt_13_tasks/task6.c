#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[]) {
    
    char upperArg[100];
    char upperPlanet[100];

    char *planets[] = {"Mercury", "Venus", "Earth","Mars", "Jupiter", "Saturn","Uranus", "Neptune", "Pluto"};
    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++) {
            
            for (int k = 0; argv[i][k]; k++) {
                upperArg[k] = toupper(argv[i][k]);
            }
            
            upperArg[strlen(argv[i])] = '\0';
            
            for (int k = 0; planets[j][k]; k++) {
                upperPlanet[k] = toupper(planets[j][k]);
            }
            upperPlanet[strlen(planets[j])] = '\0';

            if (strcmp(upperArg, upperPlanet) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }
    return 0;
}

