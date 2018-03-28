#include "ants.h"
#include "openHash.h"
/* #include "intChainHash.h" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NUM_ANTS (256)
#define UNIVERSE_DIM (4294967296)
#define HASH_SIZE (9000)
#define INTLEN (10)


typedef struct {
    int x;
    int y;
    int z;
} ant;


int main() { 
    ant *antLoc;
    antLoc = calloc(NUM_ANTS, sizeof(ant));
    
    //TODO make the stuff into pointers, passing the whole table around is bad
    //set up antspace
   //TODO make it so that the ants hold their spot and don't refresh
     
    
    // printf("HI");
    table *t = createTable(HASH_SIZE);

    
    //read input
    unsigned int input = getchar();
    unsigned char ant = input;
    int x = 0;
    int y = 0;
    int z = 0;
  // putchar('b');
    /* int ct = 0; */
    while(input != EOF) {
        /* putchar(input); */
        /* assert(ct < 18); */
        /* ct++; */
        // printf("%d", input);
            // printf("hi");
    // fflush(stdout);
        x = antLoc[input].x;
        y = antLoc[input].y;
        z = antLoc[input].z;
        //putchar('1');
        /* if(ant == NULL) { */
            /* if (input != '\n') */
        /* } */
        switch (input){
            case 'h': {
                x--;
        //putchar('2');
            };
            case 'j': {
                y--;
                y--;
        //putchar('3');
            };
            case 'k': {
                y++;
                y++;
        //putchar('4');
            };
            case 'l': {
                x++;
                x++;
        //putchar('5');
            };
            case '<': {
                z++;
                z++;
        //putchar('6');
            };
            case '>': {
            z--;
                z--;
        //putchar('7');
            };
            case '*': {
                x = 2 * x;
                y = 2 * y;
                z = 2 * z;
        //putchar('8');
            };
            case '.': {
               genInsert(t, x, y, z, ant); 
        //putchar('9');
            };
            case '?': {
                putchar(antPrint(t, x, y, z));
        //putchar('0');
            };
            case '\n': {
                unsigned int next = getchar();
                /* putchar(next); */
        //putchar('a');
                if (next == EOF) {
                    
                        input = next;
                        break;
                }
                ant = next;
            }
                }
    input = getchar();
    // putchar(input);
    }
    free(antLoc);
    tDelete(t);
    return 0;
}


