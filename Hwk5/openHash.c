#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* #include "testHash.h" */
#include "openHash.h"

#define M_VAL (100)

void genInsert(table *t,  int x, int y, int z, char ant){
    value *val;
    val = malloc(sizeof(val));
    val->x = x;
    val->y = y;
    val->z = z;
    val->ant = ant;
    /* element *ele = hashVal(key, val); */
    tInsert(t, val);
}

table *createTable(int size) {
    table *t = malloc(sizeof(table));

    t->size = 100;
    t->count = 0;
    t->items = calloc((size_t)t->size, sizeof(value*));
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
        printf("43");
        return ' ';
    }
    printf("46");
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
// int hash(unsigned char *key, const int m) {
    
//     unsigned long out = 0;
//     int c;
//     c = 0;
    
//     // while((*key != '\0') && (c = *key++)){
//     // while(*key){// != '\0') {
//     for (int i = 0; i < 1; i++){
//     printf("\n*****   %s ****\n", key);
//         printf("%d", c);
// //         fflush(stdout);
// //         out = c + out;
// //         ++key;
// //         // out = (c + (out << 16) + (out << 5) - out);
//     printf("made it to 79");
//     }
    
//     out = (int) out;
//     //TODO cite hash func
//     /* int out = 0; */
//     /* const int len = strlen(key); */
//     /* //TODO watch out this takes a while */
//     /* for (int i=0; i < len; i++) { */
//     /*     out += (c ** (len - (i+1)) * (key[i] - '0')); */
//     /* } */
//     out = out % m;
//     //TODO maybe move into for loop
//     return out;
// }

int hash(int x, int y, int z, const int size) {
    // printf("TEST\n%d\n",((x + y + z) % size));
    return ((x + y + z) % size);
}

void tInsert(table *t, value *val){
    // element *ele;
    // element *collisionEle;
    value *colVal;
    // ele = eleVal(val);
//TODO the moving by more than 1  could be good less collisions
    int hashIndex = hash(val->x, val->y, val->z , t->size);
    
    colVal = t->items[hashIndex];
    /* int loc = 1; */
    while(colVal != NULL) {
        hashIndex++;
        colVal = t->items[hashIndex];
        /* loc++;     */
    }
    t->items[hashIndex] = val;
    t->count++;
}

value *tLookup(table *t, int x, int y, int z) {
    int s = t->size;
    int hashIndex = hash(x, y, z, s);
    // printf("\n%d\n", hashIndex);
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
