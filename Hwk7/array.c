#include "array.h"


// Create a new array holding n values, all initially 0.
// Behavior is undefined if n == 0.
// Cost: O(n).
Array *arrayCreate(int (combine)(int, int), size_t n){
    Array *a = calloc(n, sizeof(int));
    /* a->combine = combine; */
    return a;
}

// Free all space used by an array.
// Cost: O(n).
void arrayDestroy(Array *);

// Return the number of elements of an array.
// Cost: O(1).
size_t arraySize(const Array *);

// Return the i-th element of an array
// or 0 if i is out of range.
// Cost: O(log n).
int arrayGet(const Array *, size_t i);

// Set the i-th element of an array to v.
// No effect if i is out of range.
// Cost: O(log n).
void arraySet(Array *, size_t i, int v);

// Return the result of aggregating the first k elements
// of an array in order using the combine function.
// If k is zero or greater than size, returns combination of all elements.
// Cost: O(log n).
int arrayCombine(const Array *, size_t k);
