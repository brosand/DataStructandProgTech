#ifndef __OPENHASH_H_
#define __OPENHASH_H_


typedef struct {
    int x;
    int y;
    int z;
    char ant;
} value;

typedef struct {
    char *key;
    value *val;
} element;


typedef struct {
    int size;
    int count;
    element **items;
} table;

typedef table *Table;


table *createTable(int size);

void genInsert(table *t, unsigned char *key, int x, int y, int z, char ant);

element *hashVal(unsigned char *key, value *val);

void tInsert(table *t, unsigned char *key, value *val);

void tDelete(table *t);

element *tLookup(table *t, unsigned char *key);

char antPrint(table *t, unsigned char *key);

int hash(int x, int y, int z, const int size);
//TODO maybe make the keys constant

#endif // __OPENHASH_H_
