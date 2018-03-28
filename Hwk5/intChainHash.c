#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

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

struct element {
    int x;
    int y;
    int z;
    char ant;
};

struct table {
  int size;
  struct chain *keys;
};

struct node {
  struct element value;
  const char *key;
  struct node *next;
};

struct chain {
    struct node *head;
    struct node *tail;
};
/* typedef struct element struct element; */
/* typedef struct dictNode Chain; */
struct element eleCreate(int x, int y, int z, char ant) {
    struct element out;
    out.x = x;
    out.y = y;
    out.z = z;
    out.ant = ant;
    return out;
}

char elePrint(Table h, const char *key) {
    return hashLookup(h, key).ant;
}

#define BASE (256)

int hashConvert(const char *s)
{
    int h;
    int m = 7919;
    unsigned const char *us;

    /* cast s to unsigned const char * */
    /* this ensures that elements of s will be treated as having values >= 0 */
    us = (unsigned const char *) s;

    h = 0;
    while(*us != '\0') {
        h = (h * BASE + *us) % m;
        us++;
    } 

    return h;
}

/* int hashConvert(const char *key) { */
/*      /\* size_t h; *\/ */
/*     int h; */
/*     unsigned const char *us; */
     
/*      us = (unsigned const char *) key; */
     
/*      h = 0; */
/*      while(*us != '\0') { */
/*          h = h * MULTIPLIER + *us; */
/*          us++; */
/*      } */
/*      /\* printf("hash value is %zu\n", h); *\/ */
/*      printf("hash value is %d\n", h); */
     
/*      return h; */
         
    
/* } */

Table hashTableCreate(int size) {
  struct table *t;

  /* int size; */

  /* size = (int) (n * ) */
  t = malloc(sizeof(Table));
  t->size = size;
  t->keys = malloc(sizeof(struct chain) * (size-1));
  for (int i = 0; i < size; i++) {
      Chain chain;// = malloc(sizeof(Chain));
      /* chain.head = NULL; */
      /* chain.tail = NULL; */
      t->keys[i] = chain;
  }
  return t;



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

void hashVal(Table h, const char *key, int x, int y, int z, char ant){
    //assume htable.keys[hashindex exists]
    struct element value = eleCreate(x,y,z,ant);
    int hashIndex = hashConvert(key);
    printf("%d",hashIndex);
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

struct element hashLookup(Table h, const char *key){
  int hashIndex = hashConvert(key);
  printf("%d", hashIndex);
  printf("this line is here");
  fflush(stdout);
  assert(h->keys[hashIndex].head != NULL);
  return((h->keys[hashIndex].head[findNode(h->keys[hashIndex].head,key)]).value);
  
  /* else { */
      /* return NULL; */
      //this is not quite right
  /* } */
  /* return -1; */
}




