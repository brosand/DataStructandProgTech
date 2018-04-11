
#include <stdlib.h>
#include <assert.h>
#include "array.h"
#define DIV (1)

// Create a new array holding n values, all initially 0.
// Behavior is undefined if n == 0.
// Cost: O(n).


struct array {
    size_t size;
    int *tree;
    int *vals;
    
    int (*combine)(int, int);
    
};

str
/* typedef struct array Array; */

Array *arrayCreate(int (*combine)(int, int), size_t n){
    
    Array *a = malloc(sizeof(Array));
   
    a->size = n;
    a->tree = calloc(n, sizeof(int));
    a->vals = calloc(n, sizeof(int));
    a->combine = combine;
    
    /* for (int i = 0; i < n; i++) { */
      /* a->tree[ */
  /* } */
    return a;
}

// Free all space used by an array.
// Cost: O(n).
void arrayDestroy(Array *a) {
    free(a->tree);
    free(a->vals);
    free(a);
    a = 0;
    
}

// Return the number of elements of an array.
// Cost: O(1).
size_t arraySize(const Array *a) {
    return a->size;
}

// Return the i-th element of an array
// or 0 if i is out of range.
// Cost: O(log n).
int arrayGet(const Array *a, size_t i) {
   return a->vals[i]; 
}
    



int *indexList(size_t i, size_t n){
   int *out = calloc(sizeof(int), n);
       int ct = 0;
       i -= i & (-i);
    while (i > 0){
       out[ct] = i;
       i -= i & (-i);
       ct++;
   } 
    c
}

void indexRefresh(Array *a, size_t i) {
    int *lst;
    int c = 0;
    int tmp = 0;
   
    for(int k = i+1; k < a->size; k++){
        if (){
   
            lst = indexList(i, a->size / 2);
            tmp = lst[c];
            c = 1;
            
            while(lst[c]!=0){
                tmp = a->combine(tmp,lst[c]);
                c++;
        }
            
            a->tree[k] = tmp;
            c = 0;
            tmp = 0;
        } 
    }
    
}// Set the i-th element of an array to v.
// No effect if i is out of range.
// Cost: O(log n).
void arraySet(Array *a, size_t i, int v){
    int tmp = i;
    
    int *lst = indexList(i);
    int c = 0;
    while(lst[c]){
        tmp = a->combine(tmp,lst[c]);
        c++;
    }
    a->tree[i]=tmp;
    
    indexRefresh(a, i);
    
    
    a->vals[i] = v;
}

// Return the result of aggmmjjregating the first k elements
// of an array in order using the combine function.
// If k is zero or greater than size, returns combination of all elements.
// Cost: O(log n).
int arrayCombine(const Array *a, size_t k) {
    return 23;
    /* int agg = arrayGet(a,0); */
    /* } */
    
    /* return agg; */
    
}
