#include <stdlib.h>
#include <assert.h>

#include "basicHash.h"


struct hTable {
  int size;
  int keys[];
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

int findNode(struct node *start, int key) {
    int out = 0;
    struct node *temp = start;
    while(temp != NULL) {
        if(temp->key = key) {
            return out
        }
        temp = temp->next;
        out ++;
    }
    return -1;
    
}

int hashLookup(HashTable htable, int key){
  int hashIndex = hashConvert(key);
  
  if(hTable.keys[hashIndex]) {
      return(hTable.keys[hashIndex]->head[findNode(hTtable.keys[hashIndex]->head)])
  }
  else {
      return -1;
      //this is not quite right
  }
}




void hashSet(Hashtable htable, int key, int value){
    //assume htable.keys[hashindex exists]
    
    struct node newTail;
    newTail = malloc(sizeof(struct node));
    
    newTail->value = value;
    newTail->key = key;
    newTail->next = NULL;
    //also think about the fact that every dictNode could be set with null head and tail
    if (hTable.keys[hashIndex]) {
        struct dictNode dNode = hTable.keys[hashIndex];
        
        dNode->tail->next = newTail;
        dNode->tail = newTail
        //do i need to free dictnode
    }
    else {
        struct dictNode dNode;
        dNode = malloc(sizeof(dictNode));
        dNode->head = newTail;
        dNode->tail = newTail;
        hTable[hashIndex] = dictNode;
    }
}
