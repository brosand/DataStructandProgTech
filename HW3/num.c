#include "num.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
/*
 * High-precision arithmetic on non-negative number in base 10.
 */

struct Num {
    int *num;
    int length;
};
/* constructs a Num from a string */
/* string contains representation of the number
 * in base 10, e.g. numCreate("314159");
 * Returns a null pointer (0) if the string contains any non-digits.
 * Leading zeros are OK: numCreate("012") parses as 12.
 * Empty string parses as 0 */
struct Num * numCreate(const char *s){
   int *out; 
   struct Num *s2;
   
   s2 = malloc(sizeof(struct Num));
   s2->length = strlen(s);
   
   if(s == '') { s2->num = 0; return s2;}
 
   if (sscanf(s, "%d", out) == 1) {
       s2->num = out;
   }
   else {
       out = 0;
       return out;
       
   }
   
   if (s2->num == 0) {
       out = 0;
       return out;
   }
   
   return s2;
   
}

/* Free all resources used by a Num */
struct void numDestroy(Num *n){
    free(n->num); 
}

/* Get the value of the i-th least significant digit of a Num.
 * Returns 0 if i is out of range.
 * Example:
 *   n = numCreate("12345");
 *   numGetDigit(n, 0) == 5
 *   numGetDigit(n, 3) == 2
 *   numGetDigit(n, 17) == 0
 *   numGetDigit(n, -12) == 0
 */
struct int numGetDigit(const Num *n, int i){
    int nlen = n->length 
    if (i+1 > nlen) {
        return 0;
    }
    int output = (n->num) % (10 ** i);
    return output;
}

/* add two Nums, returning a new Num */
/* does not destroy its inputs, caller must destroy output */
struct Num * numAdd(const Num *x, const Num *y){
    
   struct Num *s2;
   s2 = malloc(sizeof(struct Num));
   
   s2->num = ((x->num) + (y->num));
   return s2;
}

/* multiply two Nums, returning a new Num */
/* does not destroy its inputs, caller must destroy output */
struct Num * numMultiply(const Num *x, const Num *y){
     
   struct Num *s2;
   s2 = malloc(sizeof(struct Num));
   
   s2->num = ((x->num) * (y->num));
   return s2;

}

/* Print the digits of a number to file.
 * Do not print any leading zeros unless n is zero. */
struct void numPrint(const Num *n, FILE *f){
    fprintf(f, "%d", n->num);
}

