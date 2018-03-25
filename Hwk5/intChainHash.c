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
/* TODO: figure out hasher */
struct table {
  int size;
  struct dictNode *keys;
};

struct node {
  int value;
  const char *key;
  struct node *next;
};

struct dictNode {
  struct node *head;

  struct node *tail;
};

/* typedef struct dictNode Chain; */

int hashConvert(const char *key) {
     size_t h;
     unsigned const char *us;
     
     us = (unsigned const char *) key;
     
     h = 0;
     while(*us != '\0') {
         h = h * MULTIPLIER + *us;
         us++;
     }
     return h;
         
    
}

Table hashTableCreate(int size) {
  Table htable;

  /* int size; */

  /* size = (int) (n * ) */

  htable = malloc(sizeof(*htable) + sizeof(int) * (size-1));
  return htable;



}

int findNode(struct node *start, const char *key) {
    int out = 0;
    struct node *temp = start;
    while(temp != NULL) {
        if(temp->key == key) {
            return out;
        }
        temp = temp->next;
        out ++;
    }
    return -1;
    
}

void hashKey(Table h, const char *key, int value){
    //assume htable.keys[hashindex exists]
    int hashIndex = hashConvert(key);
    struct node *newTail;
    newTail = malloc(sizeof(struct node));
    
    newTail->value = value;
    newTail->key = key;
    newTail->next = NULL;
    /* assert(h->keys[hashIndex]); */
    /* (struct node*) */
    struct node *start = h->keys[hashIndex].head;
    //also think about the fact that every dictNode could be set with null head and tail
    if (start != NULL) {
        int keyChainIndex = findNode(start,key);
        
        if (keyChainIndex != -1) {
            /* h->keys[hashIndex].head->value = value; */
            /* start[key] */
            start[keyChainIndex].value = value;
            //TODO Probably won't work because not really array
        }
        else {
            h->keys[hashIndex].tail->next = newTail;
            h->keys[hashIndex].tail = newTail;
            
            /* struct Chain dNode = h.keys[hashIndex]; */
            
            /* dNode->tail->next = newTail; */
            /* dNode->tail = newTail; */
        }
        //dont forget there could be one thing in here
        //do i need to free dictnode
    }
    else {
        /* Chain *dNode; */
        /* dNode = malloc(sizeof(struct dictNode)); */
        /* dNode->head = newTail; */
        /* dNode->tail = newTail; */
        /* h[hashIndex] = dNode; */
        h->keys[hashIndex].head = newTail;
        h->keys[hashIndex].tail = newTail;
        h->size++;
    }
}
void chainFree(Chain chain) {
    struct node *start = chain.head;
    while (chain.head != NULL){
        chain.head = start->next;
        free(start);
        start = chain.head;
}
    free(chain.tail);
}

void hashDestroy(Table h) {
    for(int i = 0; i < h->size; i++) {
        Chain d = (h->keys[i]);                                   
        if (d.head != NULL) {chainFree(d);}
    }
    
    free(h->keys);
    free(h);
}




void removeKey(Table h, const char *key) {

    int hashIndex = hashConvert(key);
    /* struct node chain = h->keys[hashIndex]; */
    /* assert(chain); */
    Chain chain = h->keys[hashIndex];
    
    int chainIndex = findNode(chain.head,key);
    assert(chainIndex != -1);
    
    struct node *temp;
    temp = malloc(sizeof(struct node));
    /* temp = malloc(sizeof(struct node)); */
/* TODO THIS TEMP LINE ABOVE MIGHT BE IMPORTANT */
    //what about case where it is a one length array
    if(chainIndex == 0){
        temp = chain.head;
        chain.head = chain.head->next;
    }
    else {
        while (temp->next->key != key) {
            temp = temp->next;
         }
        if(chain.tail == temp->next) {
            free(temp->next);
            temp->next = NULL;
            chain.tail = temp;
        }
        else {
            struct node *tempNext;
            /* tempNext = malloc(sizeof(struct node)); */
            tempNext = temp->next;
            temp->next = temp->next->next;
            free(tempNext);
            //TODO this will probably cause some errors or valgrind stuff
                
        }
    }
    
    
   
}

int hashLookup(Table h, const char *key){
  int hashIndex = hashConvert(key);
  
  if(h->keys[hashIndex].head != NULL) {
      return((h->keys[hashIndex].head[findNode(h->keys[hashIndex].head,key)]).value);
  }
  /* else { */
      return -1;
      //this is not quite right
  /* } */
  /* return -1; */
}




