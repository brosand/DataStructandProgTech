#include <stdlib.h>
#include <assert.h>

#include "intChainHash.h"

#define MULTIPLIER (47)

/* TODO: abstract out linked list  */
/* TODO: build hashDestroy */
/* TODO: build or figure out whether necessary hashtablecreate */
/* TODO: fix header file */
/* TODO: test hashConvert */
/* TODO: test hashTable create */
/* TODO: test hashDestroy*/
/* TODO: test findNode*/
/* TODO: test hashLookup*/
/* TODO: test hashSet*/
/* TODO: Build removeHash */
/* TODO: test removeHash */

struct table {
  int size;
  struct dictNode *keys;
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

int hashConvert(const char *s) {
     size_t h;
     unsigned const char *us;
     
     us = (unsigned const char *) s;
     
     h = 0;
     while(*us != '\0') {
         h = h * MULTIPLIER + *us;
         us++;
     }
         
    
}

Table hashTableCreate(int n) {
  Table htable;

  /* int size; */

  /* size = (int) (n * ) */

  htable = malloc(sizeof(*htable) + sizeof(int) * (n-1));



}
void chainFree(struct dictNode chain) {
    struct node *start = chain->head;
    while (chain->head != NULL){
        chain->head = start->next;
        free(start);
        start = chain->head;
    }
    free(chain->tail);
}

void hashDestroy(Table h) {
    for(int i = 0; i < table->size; i++) {
        dictNode d = table->keys[i];
        if (d!=NULL) {chainFree(d)}
    }
    
    free(h->keys);
    free(h);
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

void removeKey(Table h, int key) {

    int hashIndex = hashConvert(key);
    struct node chain = h->keys[hashIndex];
    assert(chain);
    
    int chainIndex = findNode[key];
    assert(chainIndex != -1);
    
    struct node temp;
    temp = malloc(sizeof(node));
    //what about case where it is a one length array
    if(chainIndex == 0){
        temp = chain->head;
        chain.head = chain->head->next;
    }
    else {
        while (temp->next->key != key) {
            temp = temp->next
         }
        if(chain.tail == temp->next) {
            free(temp->next);
            temp->next = NULL;
            chain.tail = temp;
        }
        else {
            struct node tempNext;
            /* tempNext = malloc(sizeof(node)); */
            tempNext = temp->next;
            temp->next = temp->next->next;
            free(tempNext);
            //TODO this will probably cause some errors or valgrind stuff
                
        }
    }
    
    
   
}

int hashLookup(Table h, int key){
  int hashIndex = hashConvert(key);
  
  if(h.keys[hashIndex]) {
      return(h.keys[hashIndex]->head[findNode(hTtable.keys[hashIndex]->head)])
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
    if (h.keys[hashIndex]) {
        struct dictNode dNode = h.keys[hashIndex];
        
        dNode->tail->next = newTail;
        dNode->tail = newTail
        //do i need to free dictnode
    }
    else {
        struct dictNode dNode;
        dNode = malloc(sizeof(dictNode));
        dNode->head = newTail;
        dNode->tail = newTail;
        h[hashIndex] = dictNode;
    }
}
