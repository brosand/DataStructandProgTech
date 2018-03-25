

typedef struct hashTable *HashTable;

HashTable hashTableCreate(int n, int keyList[], int valueList[]);

void hashDestroy(HashTable hTable);

int hashLookup(HashTable htable, int key);

void hashSet(Hashtable htable, int key, int value);
