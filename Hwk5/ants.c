#include "ants.h"
#include "openHash.h"

#include <stdio.h>
#include <stdlib.h>

#define NUM_ANTS (256)
#define HASH_SIZE (3 )


typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} ant;



int main() { 
    ant **antLoc;
    antLoc = calloc(NUM_ANTS, sizeof(ant*));
    
    table *t = createTable(HASH_SIZE);

    
    unsigned int input = getchar();
    unsigned int nAnt = input;

    for (int i = 0; i < NUM_ANTS; i++) {
        ant *a = malloc(sizeof(ant));
        a->x = 0;
        a->y = 0;
        a->z = 0;
        antLoc[i]=a;
    }

    unsigned int x = antLoc[nAnt]->x;
    unsigned int y = antLoc[nAnt]->y;
    unsigned int z = antLoc[nAnt]->z;

    input = getchar();
    
    while(input != EOF) {
        switch (input){
            case 'h': 
            x--;
            break;

            case 'j': 
            y--;
            break;

            case 'k': 
            y++;
            break;

            case 'l': 
            x++;
            break;

            case '<': 
            z++;
            break;

            case '>': 

            z--;
            break;

            case '*': 
            x = 2 * x;
            y = 2 * y;
            z = 2 * z;
            break;

            case '.': 
            genInsert(t, x, y, z, nAnt); 
            break;

            case '?': 
            putchar(antPrint(t, x, y, z));
            break;

            case '\n': 
            input = getchar();

            if(input==EOF){
                break;
            }
            else{
                nAnt = input;
                x = antLoc[nAnt]->x;
                y = antLoc[nAnt]->y;
                z = antLoc[nAnt]->z;
            }
            break;
        }

        antLoc[nAnt]->x = x;
        antLoc[nAnt]->y = y;
        antLoc[nAnt]->z = z;

        input = getchar();
    }
    
    for (int i = 0; i < NUM_ANTS; i++) {
        free(antLoc[i]);}
        free(antLoc);
        tDelete(t);
        return 0;
    }


