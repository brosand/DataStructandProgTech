#ifndef __OPENHASH_H_
#define __OPENHASH_H_


typedef struct {
    int x;
    int y;
    int z;
    char ant;
} value;

// typedef struct {
//     // char *key;
//     value *val;
// } element;


typedef struct {
    int size;
    int count;
    value **items;
} table;

typedef table *Table;


table *createTable(int size);

void genInsert(table *t, char *key, char ant);

// value *eleVal(value *val);

void tInsert(table *t, value *val);

void tDelete(table *t);

value *tLookup(table *t, char *key);

char antPrint(table *t, char *key);

unsigned int hash(char *key, const int size);
//TODO maybe make the keys constant

#endif // __OPENHASH_H_
