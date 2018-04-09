
#include <stdlib.h>
#include "array.h"

#define DIV (1)

// Create a new array holding n values, all initially 0.
// Behavior is undefined if n == 0.
// Cost: O(n).


struct array {
    size_t size;
    int *items;
    int (*combine)(int,int);
    int *aggregates;
};
/* typedef struct array Array; */

Array *arrayCreate(int (*combine)(int, int), size_t n){
    Array *a = malloc(sizeof(Array));
    a->items = calloc(n, sizeof(int));
    a->aggregates = calloc(n, sizeof(int));
    /* a->items = malloc(sizeof(int) * n); */
    a->size = n;
    a->combine = combine;
    return a;
}

// Free all space used by an array.
// Cost: O(n).
void arrayDestroy(Array *a) {
    free(a->items);
    free(a);
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
    return a->items[i];
}

// Set the i-th element of an array to v.
// No effect if i is out of range.
// Cost: O(log n).
void arraySet(Array *a, size_t i, int v){
    if (a->size < i) {return;}
    a->items[i] = v;
    if(i == 0) {
        a->aggregates[i] = 0;
    } else {
        a->aggregates[i] = a->combine(a->aggregates[i-1],v);
    }
    /* a->size++; */
}

// Return the result of aggregating the first k elements
// of an array in order using the combine function.
// If k is zero or greater than size, returns combination of all elements.
// Cost: O(log n).
int arrayCombine(const Array *a, size_t k) {
    /* int agg = arrayGet(a,0); */
    if (a->size < k || k == 0) {k = a->size;};
    
    /* int agg = arrayGet(a,0); */
    /* for (int i = 1; i < k; i++) { */
        /* agg = (a->combine(agg, arrayGet(a,i))); */
    /* } */
    /* for (int i = 1; i < k; i++) { */
        /* agg = a->combine(agg, arrayGet(a, i)); */
    /* } */
    return a->aggregates[k-1];
    /* return agg; */
    
}
