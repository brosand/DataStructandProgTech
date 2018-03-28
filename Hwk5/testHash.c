#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "testHash.h"

element *hashVal(const char *key, value *val) {
    element *out = malloc(sizeof(element));
    out->key = strdup(key);
    //TODO do I need strdup
    out->val = val;
    return out;
}

table createTable(int size) {
    table *t = malloc(sizeof(table));

    t->size = 100;
    t->eleCount = 0;
    t->items = calloc((size_t)t->size, sizeof(struct chain*));
    //TODO what about size of struct chain
    return t;
}

delElement(element *ele) {
    free(ele->key);
    free(ele.val);
    free(ele);
    //TODO might not need to free val?
}

delChain(chain *ch) {
    
}


delTable(table *t) {
    for (int i = 0; i < t->size; i++) {
        element *ele = t->items[i];
        if (ele != NULL) {
            delElement(ele);
        }        
    }
    free(t->items);
    free(t);
}

int hash(const char *key, const int c, const int m) {
    out = 0;
    const int len = strlen(key);
    for (i=0; i < len; i++) {
        out += (c ** (len - (i+1)) * (key[i] - '0'));
    }
    out = out % m;
    return out;
}

void tInsert(table *t, const char *key, value *val){
    element *ele = hashVal(key, val);
    int hashIndex = hash(ele->key, t->size, 0);
    
}
void tDelete(table *t, const char *key);

element *tLookup(table *t, const char *key);
