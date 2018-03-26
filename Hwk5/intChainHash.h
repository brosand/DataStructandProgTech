struct element;

struct table;

struct node;

struct dictNode;

typedef struct table *Table;

typedef struct dictNode Chain;

/* typedef struct element struct element; */


/* HashTable hashTableCreate(int n, int keyList[], int valueList[]); */

/* void hashDestroy(HashTable hTable); */

/* int hashLookup(HashTable htable, int key); */

/* void hashSet(Hashtable htable, int key, int value); */

struct element eleCreate(int x, int y, int z, char ant);

char elePrint(Table h, const char *key);

int hashConvert(const char *key);

Table hashTableCreate(int size);

void hashVal(Table h, const char *key, int x, int y, int z, char ant);

void chainFree(Chain chain);

void hashDestroy(Table h);

/* int findNode(struct node *start, const char *key); */

void removeKey(Table h, const char *key);

struct element hashLookup(Table h, const char *key);
