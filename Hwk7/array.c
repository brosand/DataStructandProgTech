#include "array.h"

#include <stdlib.h>



// Create a new array holding n values, all initially 0.
// Behavior is undefined if n == 0.
// Cost: O(n).
Array *arrayCreate(int (combine)(int, int), size_t n){
Array *a = malloc(sizeof(Array));
a->items = calloc(n, sizeof(int));
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
    a->size++;
}

// Return the result of aggregating the first k elements
// of an array in order using the combine function.
// If k is zero or greater than size, returns combination of all elements.
// Cost: O(log n).
int arrayCombine(const Array *a, size_t k) {
    int agg = 0;
    for (int i = 0; i < k; i++) {
        agg = (a->combine(agg, arrayGet(a,i)));
    }
    return agg;
    
}
