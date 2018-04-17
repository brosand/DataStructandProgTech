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
    val->str = str;
    
    tInsert(t, val);
}

void resizeTable(table *oldTable){

    int oldSize = oldTable->size;

    table *t = createTable(oldSize * 2);

    for (int i = 0; i < oldSize; i++) {
        value *val = oldTable->items[i];
        
        if(val !=NULL){
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
    
    tOldDelete(t);
    
}
table *createTable(int size) {
    table *t = malloc(sizeof(table));

    t->size = size;
    t->count = 0;
    t->items = calloc(size, sizeof(value*));

    return t;
}

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

    unsigned int hash = 37;
    unsigned int c;

    while(c = *key++){
       hash = ((hash << 5) + hash) + c;
   }

   return (hash + size) % (size-1);
}

void tInsert(table *t, value *val){
    value *colVal;
    int load = t->count * 100 / t->size;

    if (load > 70) {
        resizeTable(t);
    }

    int hashIndex = hash(val->str, t->size);

    colVal = t->items[hashIndex];
    
    while(colVal != NULL && hashIndex < (t->size-2) && (strcmp(colVal->str,val->str) != 0)){
        hashIndex++;
        colVal = t->items[hashIndex];
    }

    if (hashIndex >= (t->size)-2) {
        resizeTable(t);
        tInsert(t, val);
    } else if (t->items[hashIndex] != NULL) {
        free(colVal);
        t->items[hashIndex] = val;
    } else {
        t->count++;
        t->items[hashIndex] = val;
    }
}



value *tLookup(table *t, char *str){
    int s = t->size;
    int hashIndex = hash(str, s);

    value *foundVal = t->items[hashIndex];

    if(foundVal == NULL) {
        return NULL;
    }

    while((strcmp(foundVal->str, str) != 0) && (hashIndex < (s-2))){    
    hashIndex++; 
        foundVal = t->items[hashIndex];
        
        if(foundVal == NULL) {
            return NULL;
        }
    }
    return foundVal;
    
}
