#include "ants.h"
#include "intChainHash.h"
/* #include "intChainHash.h" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ANTS (256)
#define UNIVERSE_DIM (4294967296)
#define HASH_SIZE (300)


const char *keyConvert(int x, int y, int z) {
    /* char *xx; */
    /* char *yy; */
    /* char *zz; */
    /* xx = malloc(10); */
    /* yy = malloc(10); */
    /* zz = malloc(10); */
    char * out;
    out = malloc(30);
    sprintf(out,"%010d", x);
    sprintf(&out[10],"%010d", y);
    sprintf(&out[20],"%010d", z);
    return out;
    /* atol(output, a, 10); */
    /* return a; */
    /* return atol() */
} 

int main() {
    //TODO make the stuff into pointers, passing the whole table around is bad
    //set up antspace
    Table t = hashTableCreate(HASH_SIZE);
    
    
    //read input
    char input = getchar();
    char ant = input;
    int x = 0;
    int y = 0;
    int z = 0;
  putchar('b');  
    while(input != EOF) {
        putchar('1');
        /* if(ant == NULL) { */
            /* if (input != '\n') */
        /* } */
        switch (input){
            case 'h': {
                x--;
        putchar('2');
            };
            case 'j': {
                y--;
        putchar('3');
            };
            case 'k': {
                y++;
        putchar('4');
            };
            case 'l': {
                x++;
        putchar('5');
            };
            case '<': {
                z++;
        putchar('6');
            };
            case '>': {
            z--;
        putchar('7');
            };
            case '*': {
                x = 2*x;
                y = 2*y;
                z = 2*z;
        putchar('8');
            };
            case '.': {
               hashVal(t, keyConvert(x,y,z), x, y, z, ant); 
        putchar('9');
            };
            case '?': {
                putchar(elePrint(t, keyConvert(x,y,z)));
        putchar('0');
            };
            case '\n': {
                char next = getchar();
        putchar('a');
                if (next == EOF) {
                    
                        input = next;
                        break;
                }
                ant = next;
            }
                }
    input = getchar();
    }
    return 0;
}


