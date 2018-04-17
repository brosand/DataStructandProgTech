#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "openHash.h"



char *keyConvert(int x, int y, int z) {
    char * out;
    out = malloc(31);

    sprintf(out,"%010u", x);
    sprintf(&out[10],"%010u", y);
    sprintf(&out[20],"%010u", z);

    return out;
}

void genInsert(table *t, char *str){
    value *val;
    val = malloc(sizeof(value));
    /* val->x = x; */
    /* val->y = y; */
    /* val->z = z; */
    /* val->ant = ant; */
    val->str = str;
    tInsert(t, val);
}

void resizeTable(table *oldTable){

    int oldSize = oldTable->size;

    table *t = createTable(oldSize * 2);

    for (int i = 0; i < oldSize; i++) {
        value *val = oldTable->items[i];
        
        if(val !=NULL){
            /* int x = val->x; */
            /* int y = val->y; */
            /* int z = val->z; */
            char *str = val->str;

            genInsert(t,str);
        }
    }

    oldTable->count = t->count;
    oldTable->size = t->size;

    value** oldItems = oldTable->items;
    oldTable->items = t->items;

    t->size = oldSize;
    t->items = oldItems;
   //TODO SWITCH TO t->something right? 
    /* tDelete(t); */
    tOldDelete(t);
    
}
table *createTable(int size) {
    table *t = malloc(sizeof(table));

    t->size = size;
    t->count = 0;
    t->items = calloc(size, sizeof(value*));

    return t;
}

/* char antPrint(table *t, int x, int y, int z) { */
/*     value *foundVal = tLookup(t, x, y, z); */

/*     if (foundVal == NULL) { */
/*         return ' '; */
/*     } */

/*     return foundVal->ant; */
/* } */
void tOldDelete(table *t){
    for (int i = 0; i < t->size; i++) {
        value *val = t->items[i];

        if (val != NULL) {
            free(val);
        }        
    }

    free(t->items);
    free(t);
}
void tDelete(table *t) {

    for (int i = 0; i < t->size; i++) {
        value *val = t->items[i];

        if (val != NULL) {
            free(val->str);
            free(val);
        }        
    }

    free(t->items);
    free(t);
}


unsigned int hash(char *key, int size) {

    /* char *key = keyConvert(x,y,z); */
    
    /* char *tmp = key; */
    unsigned int hash = 37;
    unsigned int c;

    /* hash = x + y + z; */
    
    while(c = *key++){
       hash = ((hash << 5) + hash) + c;
   }

   /* free(tmp); */
    
    
   return (hash + size) % (size-1);
}
//unsigned int hash = (unsigned int)crcNaive((unsigned int)(key));
void tInsert(table *t, value *val){
    value *colVal;
    int load = t->count * 100 / t->size;

    if (load > 70) {
        resizeTable(t);
    }

    int hashIndex = hash(val->str, t->size);

    colVal = t->items[hashIndex];
    
    /* while(colVal != NULL && hashIndex < (t->size-2) && ((colVal->x != val->x) || (colVal->y != val->y) || (colVal->z != val->z))) { */
    while(colVal != NULL && hashIndex < (t->size-2) && (strcmp(colVal->str,val->str) != 0)){
        hashIndex++;
        colVal = t->items[hashIndex];
    }

    if (hashIndex >= (t->size)-2) {
        resizeTable(t);
        tInsert(t, val);
    }

    else if (t->items[hashIndex] != NULL) {
        free(colVal);
        t->items[hashIndex] = val;
    }

    else {
        t->count++;
        t->items[hashIndex] = val;
    }
}



value *tLookup(table *t, char *str){
    int s = t->size;
    int hashIndex = hash(str, s);

    value *foundVal = t->items[hashIndex];

    if(foundVal == NULL) {
        /* printf("HERE"); */
        return NULL;
    }

    /* while(((foundVal->x != x) || (foundVal->y != y) || (foundVal->z != z)) &&  (hashIndex < (s-2))) { */
    while((strcmp(foundVal->str, str) != 0) && (hashIndex < (s-2))){    
    hashIndex++; 
        foundVal = t->items[hashIndex];
        
        if(foundVal == NULL) {
            return NULL;
        }
    }
    /* printf("HERE"); */
    return foundVal;
    
}


/*
 * The width of the CRC calculation and result.
 * Modify the typedef for a 16 or 32-bit CRC standard.
 */
typedef uint32_t crc;

#define WIDTH  (8 * sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))
#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */

crc
crcSlow(const uint8_t message[], int nBytes)
{
    crc  remainder = 0;	


    /*
     * Perform modulo-2 division, a byte at a time.
     */
    for (int byte = 0; byte < nBytes; ++byte)
    {
        /*
         * Bring the next byte into the remainder.
         */
        remainder ^= (message[byte] << (WIDTH - 8));

        /*
         * Perform modulo-2 division, a bit at a time.
         */
        for (uint8_t bit = 8; bit > 0; --bit)
        {
            /*
             * Try to divide the current data bit.
             */
            if (remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ POLYNOMIAL;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }
    }

    /*
     * The final remainder is the CRC result.
     */
    return (remainder);

}   /* crcSlow() */
unsigned int
crcNaive(unsigned int const message)
{
    uint8_t  remainder;	


    /*
     * Initially, the dividend is the remainder.
     */
    remainder = message;

    /*
     * For each bit position in the message....
     */
    for (uint8_t bit = 8; bit > 0; --bit)
    {
        /*
         * If the uppermost bit is a 1...
         */
        if (remainder & 0x80)
        {
            /*
             * XOR the previous remainder with the divisor.
             */
            remainder ^= POLYNOMIAL;
        }

        /*
         * Shift the next bit of the message into the remainder.
         */
        remainder = (remainder << 1);
    }

    /*
     * Return only the relevant bits of the remainder as CRC.
     */
    return (remainder >> 4);

}   /* crcNaive() */