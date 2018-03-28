#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* #include "testHash.h" */
#include "openHash.h"

#define M_VAL (100)

void genInsert(table *t,  int x, int y, int z, char ant){
    value *val;
    val = malloc(sizeof(value));
    val->x = x;
    val->y = y;
    val->z = z;
    val->ant = ant;
    /* element *ele = hashVal(key, val); */
    tInsert(t, val);
}

table *createTable(int size) {
    table *t = malloc(sizeof(table));

    t->size = size;
    t->count = 0;
    t->items = calloc(t->size, sizeof(value*));
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

unsigned int hash(int x, int y, int z, const int size) {
    /* printf("x: %d", x); */
    /* printf("y: %d", y); */
    /* printf("z: %d", z); */
    return (unsigned int)(((x + y + z) + size)%size);
    /* return 0; */
    //hopefully adding size makes it always at least 1, but make sure x y z are pos
}

void tInsert(table *t, value *val){
    value *colVal;
    colVal = malloc(sizeof(value));
//TODO the moving by more than 1  could be good less collisions
    int hashIndex = hash(val->x, val->y, val->z , t->size);
    
    colVal = t->items[hashIndex];
    
    /* int loc = 1; */
    while(colVal != NULL) {
        hashIndex++;
    /* printf (" T%d", hashIndex); */
        colVal = t->items[hashIndex];
        /* loc++;     */
    }
    t->items[hashIndex] = val;
    t->count++;
}

value *tLookup(table *t, int x, int y, int z) {
    int s = t->size;
    int hashIndex = hash(x, y, z, s);
    /* printf("\n%d\n", hashIndex); */
    value *foundVal = t->items[hashIndex];
    if(foundVal == NULL) {
        return NULL;
    }
        // printf("%d\n", hashIndex);
        
    while((foundVal->x != x) && (foundVal->y != y) && (foundVal->z != z) &&  (hashIndex < s)) {
        // printf("%d\n", hashIndex);
        hashIndex++; 
        foundVal = t->items[hashIndex];
        if(foundVal != NULL) {
            return NULL;
        }
    }
    return foundVal;
    
}
