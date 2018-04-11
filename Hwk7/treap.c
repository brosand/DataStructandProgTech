#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "array.h"

#define NUM_CHILDREN (2)
 
#define LEFT (0)
#define RIGHT (1)


// Create a new array holding n values, all initially 0.
// Behavior is undefined if n == 0.
// Cost: O(n).


struct array {
    size_t size;
    size_t index;
    int agg;
    int value;
    int heapKey;
    int (*combine)(int, int);
    struct array **child;
    
};
/* typedef struct array Array; */


void arrayDestroy(Array *a) {
    /* printf("HI\n"); */
    if(a!=0) {
        for (int i = LEFT; i <= RIGHT; i++) {
            arrayDestroy((a)->child[i]);
        }
    
    free(a);
    a = 0;
    }
}


// Free all space used by an array.
// Cost: O(n).
// Return the number of elements of an array.
// Cost: O(1).
size_t arraySize(const Array *a) {
    return a->size;
}

// Return the i-th element of an array
// or 0 if i is out of range.
// Cost: O(log n).
int arrayGet(const Array *a, size_t i) {
    /* printf("67"); */
    /* printf("%zu\n",i); */
    if (a==0){
        printf("68");
        return 0;
    }
    else if(i == a->index) {
        /* printf("HI"); */
        return a->value;
    }
    else if(i < a->index) {
        /* printf("77"); */
    /* printf("%d\n",a->index); */
        return arrayGet(a->child[LEFT], i);
    } else {
        /* printf("80"); */
    /* printf("**%zu**\n",a->index); */
        return arrayGet(a->child[RIGHT], i);
    }
}
int fixAgg(Array *);
int fixAgg(Array *a){
    if(a->child[LEFT] == 0){
        if(a->child[RIGHT]==0) {
            return(a->value);
        }
        else{
            return a->combine(a->child[RIGHT]->agg, v);
        }
    }
    else if(a->child[RIGHT] == 0){
        return a->combine(v, a->child[LEFT]->agg, v)
    }
    return()
}
void treapRotate(Array **a, size_t i) {
    
    assert(a);
    Array *ch = *a;
    assert(ch);
    Array *gr = ch->child[i];
    assert(gr);
    Array *mSub = gr->child[!i];
    
    *a = gr;
    gr->child[!i] = ch;
    ch->child[i] = mSub;
    /* gr->agg = fixAgg(ch); */
    /* ch->agg = fixAgg(gr); */
}

// Set the i-th element of an array to v.
// No effect if i is out of range.
// Cost: O(log n).

void arraySetR(Array **a, size_t i, int v){
    /* printf("i val: %zu\n", i); */
    /* assert(a); */
    /* assert(i < a->) */
    if(*a == 0) {
       /* if(a == null || a ==) { */
        *a = malloc(sizeof(Array));
        (*a)->index = i;
        (*a)->heapKey = rand();
        (*a)->value = v;
        (*a)->agg = v;
        //rand decl
         
        (*a)->child = calloc(sizeof(Array*), NUM_CHILDREN);
        (*a)->child[LEFT] = (*a)->child[RIGHT] = 0;
    } else if (i == (*a)->index) {
        (*a)->value = v;
        return;
        //is this sufficient
    } else if (i < (*a)->index) {
        arraySetR(&(*a)->child[LEFT], i, v);
    } else {
        arraySetR(&(*a)->child[RIGHT], i, v);
    }
   //TODO THIS RUNS EVERY TIME RN 
    for(int d = LEFT; d <= RIGHT; d++) {
        if((*a)->child[d] != 0 && (*a)->child[d]->heapKey > (*a)->heapKey) {
            treapRotate(a, d);
        }
    }
}   
void arraySet(Array *a, size_t i, int v){
    arraySetR(&a, i, v);
}
// Return the result of aggregating the first k elements
// of an array in order using the combine function.
// If k is zero or greater than size, returns combination of all elements.
// Cost: O(log n).
int arrayCombine(const Array *a, size_t k) {
   /* return arrayGet(a, k)->aggregate;  */
   return 1; 
    /* for (int i = 0; i < k; i++) { */
        /* agg = a->combine(agg, arrayGet(a, i)); */
    /* } */
    
    /* return agg; */
    
}
Array *arrayCreate(int (*combine)(int, int), size_t n){
    /* Array *a = malloc(sizeof(Array)); */
    /* a->size = n; */
    /* a->index = 0; */
    /* a->child = malloc(sizeof(child)); */
    /* a->child = calloc(sizeof(Array*), NUM_CHILDREN); */
    /* a->child[LEFT] = a->child[RIGHT] = 0; */
    Array *a = 0;
    /* printf("%zu\n",n); */
    for (int i = 0; i < n; i++) {
        /* printf("38"); */
        arraySetR(&a, i, 0);
        
    }
    a->size = n;
    a->combine = combine;
    return a;
}
