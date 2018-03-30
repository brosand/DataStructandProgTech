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
void genInsert(table *t,  int x, int y, int z, char ant){
    value *val;
    val = malloc(sizeof(value));
    val->x = x;
    val->y = y;
    val->z = z;
    val->ant = ant;

    tInsert(t, val);
}

void resizeTable(table *oldTable){
        
    int oldSize = oldTable->size;
    table *t = createTable(oldSize * 2);
    for (int i = 0; i < oldSize; i++) {
        value *val = oldTable->items[i];
        if(val !=NULL){
            int x = val->x;
            int y = val->y;
            int z = val->z;
            char ant = val->ant;
            genInsert(t,x,y,z,ant);
        }
       }
    oldTable->count = t->count;
    oldTable->size = t->size;
    t->size = oldSize;
    value** oldItems = oldTable->items;
    oldTable->items = t->items;
    t->items = oldItems;
    
    tDelete(t);
    
        /* value *valO = (*oldTable)->items[i]; */
/*             if (valO != NULL) { */
/*                 value *val = malloc(sizeof(value)); */
/*                 val->x = valO->x; */
/*                 val->y = valO->y; */
/*                 val->z = valO->z; */
/*                 val->ant = valO->ant; */
/*                 tInsert(t, val); */
/*         }  */
/*     } */
/*     table *tmp = malloc(sizeof(table)); */
/*     tmp->size = oldSize; */
/*     tmp->count = (*oldTable)->count; */
/*     tmp->items = (*oldTable)->items; */
/*     tDelete(tmp); */
/*     (*oldTable) = t; */
/* } */
}
table *createTable(int size) {
    table *t = malloc(sizeof(table));

    t->size = size;
    t->count = 0;
    t->items = calloc(size, sizeof(value*));
    //TODO what about size of struct chain
    //TODO element* right?
    return t;
}

// void delVal(value *val) {
//     free(val);
//     //TODO might not need to free val?
// }

char antPrint(table *t, int x, int y, int z) {
    // printf("************\n%s\n",key);
    value *foundVal = tLookup(t, x, y, z);
    // printf("FUCKING MADE IT TO SOMETHING");
    if (foundVal == NULL) {
        /* printf("43"); */
        return ' ';
    }
    /* printf("46"); */
    return foundVal->ant;
    // return ((tLookup(t,key)->val)->ant);
}

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

/* unsigned int hash(int x, int y, int z, const int size) { */
/*     return (((x + y + z) + size) % (size-1)); */
/* } */

int hash(int x, int y, int z, int size) {
        
        char *key = keyConvert(x,y,z);
        
        char *tmp = key;
        /* key = keyConvert(x,y,z); */
        unsigned int hash = 5381;
        unsigned int c;
        
        hash = x + y + z;
        
        while(c = *key++){
            /* char *tmp = (key & 5; */
            /* hash = ((hash << 5) | (hash >> (sizeof(hash) - 5))); */
           hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
            /* free(tmp); */
            /* hash = hash + size; */
        }
//         if(key){free(key);} 
        /* if (key) {free(*key);} */
        free(tmp);
         // printf("hashed to %d", ((hash+size)%(size-1))); 
        /* printf("size is: %d", size); */
        // int test = (hash+size) % size;
        return (hash + size) % (size-1);
    }

void tInsert(table *t, value *val){
    value *colVal;
    int load = t->count * 100 / t->size;
    if (load > 70) {
        resizeTable(t);
    }
    /* colVal = malloc(sizeof(value)); */
//TODO the moving by more than 1  could be good less collisions
    
    /* printf("x%d, y%d, z%d, s%d\n",val->x, val->y, val->z , t->size); */
    
    int hashIndex = hash(val->x, val->y, val->z , t->size);
    /* printf("%d\n", hashIndex); */

    colVal = t->items[hashIndex];
    
    /* int loc = 1; */
    while(colVal != NULL && hashIndex < (t->size-2) && ((colVal->x != val->x) || (colVal->y != val->y) || (colVal->z != val->z))) {
    /* printf (" T%d", hashIndex); */
        hashIndex++;
        colVal = t->items[hashIndex];
        /* loc++;     */
    }
    if (hashIndex >= (t->size)-2) {
        /* free(colVal); */
        resizeTable(t);
        tInsert(t, val);
    }
    else if (t->items[hashIndex] != NULL) {
        /* if (colVal !=NULL){free(colVal);} */
        free(colVal);
        t->items[hashIndex] = val;
        }
    else {
        t->count++;
        t->items[hashIndex] = val;
        }

    }


    // printf("\nINant %c hashed to %d\n", val->ant, hashIndex);


value *tLookup(table *t, int x, int y, int z) {
    int s = t->size;
    int hashIndex = hash(x, y, z, s);
    /* printf("\n%d\n", hashIndex); */
    value *foundVal = t->items[hashIndex];
    if(foundVal == NULL) {
        return NULL;
    }
        // printf("%d\n", hashIndex);
        
    while(((foundVal->x != x) || (foundVal->y != y) || (foundVal->z != z)) &&  (hashIndex < (s-2))) {
        // printf("%d\n", hashIndex); 
        hashIndex++; 
        /* printf("hash:%d(%d)",hashIndex,s); */
        foundVal = t->items[hashIndex];
        if(foundVal == NULL) {
            return NULL;
        }
    }
    // printf("\nLUant %c hashed to %d\n", foundVal->ant, hashIndex);
    
    /* printf("wantx%u, y%u, z%u\n", x, y, z); */
    /* printf("other: x%u, y%u, z%u\n", foundVal->x, foundVal->y, foundVal->z); */
    return foundVal;
    
}
