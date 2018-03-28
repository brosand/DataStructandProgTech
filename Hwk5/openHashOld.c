#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* #include "testHash.h" */
#include "openHash.h"

#define M_VAL (100)

void genInsert(table *t, unsigned char *key, int x, int y, int z, char ant){
    value *val;
    val = malloc(sizeof(val));
    val->x = x;
    val->y = y;
    val->z = z;
    val->ant = ant;
    /* element *ele = hashVal(key, val); */
    tInsert(t, key, val);
}

element *eleVal(value *v) {
    element *out = malloc(sizeof(element));
    /* out->key = strdup(key); */
    //TODO do I need strdup and key const
    out->val = v;
    return out;
}

table *createTable(int size) {
    table *t = malloc(sizeof(table));

    t->size = 100;
    t->count = 0;
    t->items = calloc((size_t)t->size, sizeof(element*));
    //TODO what about size of struct chain
    //TODO element* right?
    return t;
}

void delElement(element *ele) {
    free(ele->key);
    free(ele->val);
    free(ele);
    //TODO might not need to free val?
}

char antPrint(table *t, unsigned char *key) {
    // printf("************\n%s\n",key);
    element *foundEle = tLookup(t,key);
    printf("FUCKING MADE IT TO SOMETHING");
    if (foundEle == NULL) {
        return ' ';
    }
    return foundEle->val->ant;
    // return ((tLookup(t,key)->val)->ant);
}

void tDelete(table *t) {
    
    for (int i = 0; i < t->size; i++) {
        element *ele = t->items[i];
        if (ele != NULL) {
            delElement(ele);
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
//         fflush(stdout);
//         out = c + out;
//         ++key;
//         // out = (c + (out << 16) + (out << 5) - out);
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
    return ((x + y + z) % size);
}

void tInsert(table *t, unsigned char *key, value *val){
    element *ele;
    element *collisionEle;

    ele = eleVal(val);
//TODO the moving by more than 1  could be good less collisions
    int hashIndex = hash(val->x, val->y, val->z , t->size);
    
    collisionEle = t->items[hashIndex];
    /* int loc = 1; */
    while(collisionEle != NULL) {
        hashIndex++;
        collisionEle = t->items[hashIndex];
        /* loc++;     */
    }
    t->items[hashIndex] = ele;
    t->count++;
}

element *tLookup(table *t, unsigned char *key) {
    int s = t->size;
    int hashIndex = hash(key, s);
    element *foundEle = t->items[hashIndex];
    if(foundEle == NULL) {
        return NULL;
    }
        printf("%d\n", hashIndex);
        
    while((foundEle->key != key) && (hashIndex < s)) {
        printf("%d\n", hashIndex);
        hashIndex++; 
        foundEle = t->items[hashIndex];
        if(foundEle != NULL) {
            return NULL;
        }
    }
    return foundEle;
    
}
