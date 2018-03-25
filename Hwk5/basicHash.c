#include <stdlib.h>
#include <assert.h>

#include "basicHash.h"


struct hTable {
  int size;
  int keys[1];
};

struct node {
  int value;
  int key;
  struct node *next;
};

struct dictNode {
  struct node *head;

  struct node *tail;
};

HashTable hashTableCreate(int n, int keyList[], int valueList[]) {
  HashTable htable;

  int size;

  size = (int) (n * )

  htable = malloc(sizeof(*htable) + sizeof(int) * (size-1));



}

void hashDestroy(HashTable hTable) {

}

int findNode(struct node)

int hashLookup(HashTable htable, int key){
  int hashIndex = hashConvert(key);
  int i = 0;

  hTable[hashIndex]->head.key;
  int out =
  //don't forget case where the hashindex isn't there
  while(hTable[hashIndex]->head.key != key) {

  }



  int probe;

  for(probe = key % size;
      htable->keys[probe] != NULL;
      probe = (probe + 1) % size) {
        if(hTable->keys[probe] == id) {
          return hTable->keys
        }
      }
}

void hashSet(Hashtable htable, int key, int value){

}
