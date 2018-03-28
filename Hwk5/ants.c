#include "ants.h"
#include "openHash.h"
/* #include "intChainHash.h" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NUM_ANTS (256)
#define UNIVERSE_DIM (4294967296)
#define HASH_SIZE (90000)
#define INTLEN (10)


typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} ant;


int main() { 
    ant **antLoc;
    antLoc = calloc(NUM_ANTS, sizeof(ant*));
    
    //TODO make the stuff into pointers, passing the whole table around is bad
    //set up antspace
   //TODO make it so that the ants hold their spot and don't refresh
     
    
    // printf("HI");
    table *t = createTable(HASH_SIZE);

    
    //read input
    unsigned int input = getchar();
    unsigned int nAnt = input;
    for (int i = 0; i < NUM_ANTS; i++) {
        /* printf("%d ", i); */
        ant *a = malloc(sizeof(ant));
        a->x = 0;
        a->y = 0;
        a->z = 0;
        antLoc[i]=a;
    }
    unsigned int x = antLoc[nAnt]->x;
    unsigned int y = antLoc[nAnt]->y;
    unsigned int z = antLoc[nAnt]->z;
    /* printf("%d\n\n\n\n\n", antLoc[ant].x); */
    /* int ct = 0; */
    input = getchar();
    /* unsigned int q = antLoc[100]->x; */
    while(input != EOF) {
    /* printf("input: %c\n", input); */
    /* q+=10; */
    /* antLoc[100]->x = antLoc[100]->x + 10; */
        /* input = getchar(); */
        /* assert(ct < 18); */
        /* ct++; */
        // printf("%d", input);
            // printf("hi");
    // fflush(stdout);
       
        /* printf("x: %d\n", x); */
        /* printf("y: %d\n", y); */
        /* printf("z: %d\n", z); */
        //putchar('1');
        /* if(ant == NULL) { */
            /* if (input != '\n') */
        /* printf("57 "); */
        /*     putchar(input); */
        /*     putchar(input); */
        /*     printf(" 59"); */
        /* /\*     /\\* putchar('?'); *\\/ *\/ */
        /* /\*     /\\* putchar('\?'); *\\/ *\/ */
        /*     putchar('\n'); */
        /* /\* } *\/ */
    /* printf("ant:%c x%u, y%u, z%u\n",nAnt, x, y, z); */
        switch (input){
            case 'h': 
                x--;
        //putchar('2');
                break;
            case 'j': 
                y--;
        //putchar('3');
                break;
            case 'k': 
                y++;
        //putchar('4');
                break;
            case 'l': 
                /* printf("79\n"); */
                x++;
        //putchar('5');
                break;
            case '<': 
                z++;
        //putchar('6');
                break;
            case '>': 

                z--;
        //putchar('7');
                break;
            case '*': 
                x = 2 * x;
                y = 2 * y;
                z = 2 * z;
        //putchar('8');
                break;
            case '.': 
    /* printf("x%u, y%u, z%u\n",x, y, z); */
                
    /* printf("write: x%u, y%u, z%u\n",x, y, z); */
               genInsert(t, x, y, z, nAnt); 
        //putchar('9');
               break;
            case '?': 
                /* printf("99"); */
    /* printf("Lookup: x%u, y%u, z%u\n",x, y, z); */
                /* printf("output: %c\n", antPrint(t,x,y,z)); */
                putchar(antPrint(t, x, y, z));
        //putchar('0');
                break;
            case '\n': 
                input = getchar();
                
                /* printf("input: %c\n", input); */
                if(input==EOF){
                break;
                }
                else{
                    /* printf("HIHI\n"); */
                nAnt = input;
                x = antLoc[nAnt]->x;
                y = antLoc[nAnt]->y;
                z = antLoc[nAnt]->z;
                }
                /* putchar(next); */
                /* printf("109\n"); */
                /* if (input == EOF) { */
                        /* break; */
                break;
        }
    /* printf("140: %c\n", nAnt); */
    antLoc[nAnt]->x = x;
    antLoc[nAnt]->y = y;
    antLoc[nAnt]->z = z;
    
    input = getchar();
    // putchar(input);
    }
    /* printf("\n\ntest%d\n\n",  antLoc[100]->x); */
        
    
    /* for (unsigned int i = 0; i < NUM_ANTS; i++) { */
        /* printf("Ant %c is at x: %d, y: %d, z: %d\n", nAnt, antLoc[i]->x, antLoc[i]->y, antLoc[i]->z); */
    /* } */
    
    /* putchar('.'); */
    /* putchar('?'); */
    /* putchar('*'); */
    free(antLoc);
    tDelete(t);
    return 0;
}


