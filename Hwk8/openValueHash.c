#include <stdlib.h>
#include <stdio.h>

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
    
    tDelete(t);
    
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

void tDelete(table *t) {

    for (int i = 0; i < t->size; i++) {
        value *val = t->items[i];

        if (val != NULL) {
            free(val);
        }        
    }

    free(t->items);
    free(t);
}


unsigned int hash(char *key, int size) {

    /* char *key = keyConvert(x,y,z); */
    
    /* char *tmp = key; */
    unsigned int hash = 5381;
    unsigned int c;

    /* hash = x + y + z; */
    
    while(c = *key++){
       hash = ((hash << 5) + hash) + c;
   }

   /* free(tmp); */
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
    
    /* while(colVal != NULL && hashIndex < (t->size-2) && ((colVal->x != val->x) || (colVal->y != val->y) || (colVal->z != val->z))) { */
    while(colVal != NULL && hashIndex < (t->size-2) && (colVal->str != val->str)){
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
        return NULL;
    }

    /* while(((foundVal->x != x) || (foundVal->y != y) || (foundVal->z != z)) &&  (hashIndex < (s-2))) { */
    while((foundVal->str != str) && (hashIndex < (s-2))){    
    hashIndex++; 
        foundVal = t->items[hashIndex];
        
        if(foundVal == NULL) {
            return NULL;
        }
    }
    return foundVal;
    
}
