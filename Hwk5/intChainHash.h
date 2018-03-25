

typedef struct table *Table;

typedef struct dictNode Chain;


/* HashTable hashTableCreate(int n, int keyList[], int valueList[]); */

/* void hashDestroy(HashTable hTable); */

/* int hashLookup(HashTable htable, int key); */

/* void hashSet(Hashtable htable, int key, int value); */


int hashConvert(const char *key);

Table hashTableCreate(int size);

void hashKey(Table h, const char *key, int value);

void chainFree(Chain chain);

void hashDestroy(Table h);

/* int findNode(struct node *start, const char *key); */

void removeKey(Table h, const char *key);

int hashLookup(Table h, const char *key);
