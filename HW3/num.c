#include "num.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
/*
 * High-precision arithmetic on non-negative number in base 10.
 */

struct num {
    int length;
    int *data;
};
/* constructs a num from a string */
/* string contains representation of the number
 * in base 10, e.g. numCreate("314159");
 * Returns a null pointer (0) if the string contains any non-digits.
 * Leading zeros are OK: numCreate("012") parses as 12.
 * Empty string parses as 0 */
 struct num * numCreate(const char *s){
   struct num *s2; 
   s2 = malloc(sizeof(struct num));
   s2->length = strlen(s);
   s2->data = malloc(sizeof(int) * s2->length);
   
   if(strlen(s) == 0) { s2->data = 0; return s2;}
   for (int i = 0; i < strlen(s); i++) {
       if (!(isdigit(s[i]))) {
           return NULL;
       }
       int val = s[i] - '0';
       /* if ((isdigit(val))) { */
               s2->data[i] = val;
           /* } */
               }
   return s2;
   
}

/* Free all resources used by a num */
void numDestroy(Num *n){
    free(n->data);
    free(n);
    
}

/* Get the value of the i-th least significant digit of a num.
 * Returns 0 if i is out of range.
 * Example:
 *   n = numCreate("12345");
 *   numGetDigit(n, 0) == 5
 *   numGetDigit(n, 3) == 2
 *   numGetDigit(n, 17) == 0
 *   numGetDigit(n, -12) == 0
 */
 int numGetDigit(const Num *n, int i){
    int nlen = n->length;
    int maxlen = nlen;
    for (int j = 0; j < nlen; j++) {
        if ((n->data[j]) == 0) {
                maxlen = maxlen - 1;
            }
        else {
           break;
        }
    }
    if (i > (maxlen-1) || i < (0)) {return 0;}
    return n->data[nlen - i - 1];
}

/* add two nums, returning a new Num */
/* does not destroy its inputs, caller must destroy output */
struct num * numAdd(const Num *x, const Num *y){
    
    /* CHECK TO SEE IF THE +1 IS RIGHT THERE MIGHT BE ONE OFF ON THE LENGTHS OF ARRAYS */
   struct num *s2;
   s2 = malloc(sizeof(struct num));
   int maxlen = 0;
   
   if (x->length > y->length) {
       maxlen = (x->length + 1);
   }
   else {
       maxlen = (y->length + 1);
   }
   s2->length = maxlen; 
   s2->data = malloc(sizeof(int) * s2->length);
   int carry = 0;
   int a = 0;
   int b = 0;
   int sum = 0;
   int remainder = 0;
   /* printf("numGetDigits %d", (numGetDigit(y,0))); */
   for (int i = 0; i < maxlen; i++) {
       /* if ((x->length) > i) { */
       if (i > y->length) {
           for (int l = i; l < maxlen; l++) {
               s2->data[maxlen-l-1] = 0;
           }
           break;
       }
           a = numGetDigit(x,i);
           b = numGetDigit(y,i);

       sum = (a + b + carry);
       remainder = (sum % 10);
       carry = sum / 10;
       s2->data[maxlen-i-1] = remainder;

   }
    
   return s2;
}

/* multiply two nums, returning a new Num */
/* does not destroy its inputs, caller must destroy output */
struct num * numMultiply(const Num *x, const Num *y){
     
   /* CHECK TO SEE IF THE +1 IS RIGHT THERE MIGHT BE ONE OFF ON THE LENGTHS OF ARRAYS */
   struct num *s2;
   s2 = malloc(sizeof(struct num));
   int maxlen = 0;
   maxlen = (x->length + y->length);
   
   int tLen = maxlen;
   s2->length = maxlen;
   
   s2->data = malloc(sizeof(int)* maxlen);

  /* puts("157") ; */
      for (int j = 0; j < x->length ; j++) {
          struct num *tempMult;
          tempMult=malloc(sizeof(struct num));
       
  /* puts("160") ; */
       /* printf("164:tLen:  %d\n",tLen); */
  /* puts("163") ; */
       tempMult->length = maxlen;

  /* puts("157"); */
       tempMult->data = malloc(sizeof(int)*maxlen);
       /* puts("168"); */
       int a = numGetDigit(x,j);
       int b = 0;
       int carry = 0;
       int remainder = 0;
       int product = 0;
  /* puts("171") ; */
      /* numPrint(tempMult, stdout);  */
       for (int k = 0; k < maxlen; k++) {
           if (tLen - k - 1 < 0) {
               break;
           }
           /* puts("180"); */
           b = numGetDigit(y,k);

           product = (a * b + carry);
           remainder = (product % 10);
           carry = (product / 10);
           /* if (k> 8) { */
           /* printf("sumfornext: %d\n", (tLen-k-1)); */
           /* printf("product %d\n", product); */
           
           /* printf("remainder %d\n", remainder); */
           /* printf("carry %d\n", carry); */
           /* printf("b %d\n", b); */
       /* } */
           tempMult->data[tLen-k-1] = remainder;

       }
       /* if (carry != 0) { */
       /*     tempMult->data[tLen-y->length] = remainder; */
           
       /* } */
       /* for (int m = y->length; m < tLen; m++) { */
           /* tempMult->data[tLen-y->length-1] = 0; */
       /* } */
   /* numPrint(tempMult, stdout); */
       
       s2 = numAdd(tempMult, s2);
       /* does this need to change somehow, is this bad? */
       /* numDestroy(tempMult); */
       /* puts("SDF"); */
       free(tempMult->data);
       /* tLen --; */
           
   /* puts("--"); */
       
   }
   /* puts("***FDDF"); */
   /* numDestroy(tempMult); */
   /* free(tempMult); */
   /* puts("195"); */
   /* puts("____________________________"); */
   /* numPrint(s2, stdout); */
   return s2;

}

/* Print the digits of a number to file.
 * Do not print any leading zeros unless n is zero. */
void numPrint(const Num *n, FILE *f){
    int last = 0;
    for (int i = 0; i < n->length; i++) {
        /* printf("last is %d", last); */

        if (last == 0) {
            if (n->data[i] == 0) {
            /* if (last == 0) { */
                /* printf("length is %d",n->length); */
                /* printf("item 1 is %d",n->data[0]); */
                if (n->length == i+1) {
                    fputc(n->data[i] + '0', f);
                }
                /* test functionality of continue */
                continue;
            /* } */
                /* else { */
                
                /* /\* printf("%d", n->data[i]); *\/ */
                /*     fputc(n->data[i],f); */
                /*     last = 1; */
                /* } */
            }
        }
        fputc(n->data[i] + '0',f);
        last = 1;
    }
    /* if (last == 0) { */
    /*         fputc('0',f); */
    /*     } */
    /* fprintf(f, "%d", n->data); */

}

