#ifndef __OPENHASH_H_
#define __OPENHASH_H_


typedef struct {
    int x;
    int y;
    int z;
    char ant;
} value;

typedef struct {
    int size;
    int count;
    value **items;
} table;

typedef table *Table;

char *keyConvert(int x, int y, int z);
                 
table *createTable(int size);

void genInsert(table *t, int x, int y, int z, char ant);

void tInsert(table *t, value *val);

void tDelete(table *t);

value *tLookup(table *t, int x, int y, int z);

char antPrint(table *t, int x, int y, int z);

unsigned int hash(int x, int y, int z, const int size);

#endif // __OPENHASH_H_
