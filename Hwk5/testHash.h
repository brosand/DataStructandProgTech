#ifndef __TESTHASH_H_
#define __TESTHASH_H_


typedef struct {
    int x;
    int y;
    int z;
    char ant;
} value;

typedef struct {
    char *key;
    struct value val
} element;

typedef struct {
    struct element *head;
    struct element *tail;
} chain;

typedef struct {
    int size;
    int eleCount;
    chain **items;
} table;


void tInsert(table *t, const char *key, value *val);

void tDelete(table *t, const char *key);

element *tLookup(table *t, const char *key);


#endif // __TESTHASH_H_
