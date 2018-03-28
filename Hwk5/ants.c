#include "ants.h"
#include "openHash.h"
/* #include "intChainHash.h" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ANTS (256)
#define UNIVERSE_DIM (4294967296)
#define HASH_SIZE (8000)
#define INTLEN (10)


typedef struct {
    int x;
    int y;
    int z;
} ant;

// char *keyConvert(int x, int y, int z) {
//     /* char *xx; */
//     /* char *yy; */
//     /* char *zz; */
//     /* xx = malloc(10); */
//     /* yy = malloc(10); */
//     /* zz = malloc(10); */
//     char *outx;
//     char *outy;
//     char *outz;
//     int lenx = snprintf( NULL, 0, "%d", x );
//     int leny = snprintf( NULL, 0, "%d", y );
//     int lenz= snprintf( NULL, 0, "%d", z );

//     // len = (int)((ceil(log10(z))+1)*sizeof(char))

//     outx = malloc(lenx + 1);
//     outy = malloc(leny + 1);
//     outz = malloc(lenz + 1);

//     snprintf(outx, lenx + 1, "%010d", x);
//     snprintf(outy, leny + 1, "%010d", y);
//     snprintf(outz, lenz + 1, "%010d", z);

    
   
//     return out;
//     /* atol(output, a, 10); */
//     /* return a; */
//     /* return atol() */
// } 

int main() {
    ant *antLoc;
    antLoc = calloc(NUM_ANTS, sizeof(ant));
    
    //TODO make the stuff into pointers, passing the whole table around is bad
    //set up antspace
   //TODO make it so that the ants hold their spot and don't refresh
     
    
    // printf("HI");
    table *t = createTable(HASH_SIZE);

    
    //read input
    unsigned char input = getchar();
    unsigned char ant = input;
    int x = 0;
    int y = 0;
    int z = 0;
  // putchar('b');  
    while(input != EOF) {
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
                unsigned char next = getchar();
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


