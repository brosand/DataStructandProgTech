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
 int slen = strlen(s);
 if(slen == 0) { s2->data = 0; return s2;}
 for (int i = 0; i < slen; i++) {
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
 struct num *tempMult;
 int maxlen = 0;
 maxlen = (x->length + y->length);

 s2 = malloc(sizeof(struct num));
 s2->length = maxlen;
 s2->data = malloc(sizeof(int)* maxlen);


 tempMult=malloc(sizeof(struct num));
 tempMult->data = malloc(sizeof(int)*maxlen);
 tempMult->length = maxlen;

 int tLen = maxlen;

 for (int j = 0; j < x->length ; j++) {

   int a = numGetDigit(x,j);
   int b = 0;
   int carry = 0;
   int remainder = 0;
   int product = 0;

   for (int k = 0; k < maxlen; k++) {
     if (tLen - k - 1 < 0) {
       break;
     }

     b = numGetDigit(y,k-j);
     product = (a * b + carry);
     remainder = (product % 10);
     carry = (product / 10);

     tempMult->data[tLen-k-1] = remainder;
   }

   s2 = numAdd(tempMult, s2);


 }
 return s2;

}

/* Print the digits of a number to file.
 * Do not print any leading zeros unless n is zero. */
void numPrint(const Num *n, FILE *f){
  int last = 0;
  for (int i = 0; i < n->length; i++) {
    int ndat = numGetDigit(n,i);

    if (last == 0) {
      if (ndat == 0) {
        if (n->length == i+1) {
          fputc(ndat + '0', f);
        }
        continue;
      }
    }
    fputc(ndat + '0',f);
    last = 1;
  }

}

