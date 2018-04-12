#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"

// Create a new array holding n values, all initially 0.
// Behavior is undefined if n == 0.
// Cost: O(n).


struct array {
    size_t size;
    int aggregate;
    int index;
    int value;
    int (*combine)(int, int);
    struct array *left;
    struct array *right;
    
};
Array *arrayCreateR(int (*combine)(int, int), size_t n, size_t k);

Array *arrayCreate(int (*combine)(int, int), size_t n){

    Array *a = malloc(sizeof(Array));

    a->size = n;
    a->index = n/2;
    a->combine = combine;
    int l = 0;
    if (n%2 != 0){l = 1;}
    
    if(n == 1){
        a->left = a->right = 0;
        return a;
    }
    
    a->left = arrayCreateR(combine, n/2, 0);
    a->right = arrayCreateR(combine, n/2 + l, n/2);

    return a;

}

Array *arrayCreateR(int (*combine)(int, int), size_t n, size_t k){
    assert(n!=0);
    Array *a = malloc(sizeof(Array));
    int l = 0;
    if (n%2 != 0){l = 1;}
    a->size = n;
    a->index = k;
    a->value = 0;
    a->aggregate = 0;
    a->combine = combine;
    
    if(n == 1){
    /* printf("deep: %zu\n",k); */
        a->left = a->right = 0;
        return a;
    }
    /* printf("index: %zu, size: %zu \n containing\n",k,n); */
    a->left = arrayCreateR(combine, n/2, a->index);
    a->right = arrayCreateR(combine, n/2 + l, a->index + n/2);
    //TODO what about odd?
    return a;

    
}

// Free all space used by an array.
// Cost: O(n).
void arrayDestroy(Array *a) {
    if(a->left!=0){arrayDestroy(a->left);}
    if(a->right!=0){arrayDestroy(a->right);}
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
// int arrayPull(Array *a, size_t i) {
   
// }
int arrayGet(const Array *a, size_t i) {
    if (a->index == i && a->size == 1){return a->value;}
    /* printf("found index: %d, looking for: %zu\n", a->index, i); */
    assert(a);
    if (a->right->index > i){
        if(a->left){
            return arrayGet(a->left, i);
        }
        assert(0);
     }
     /* else if (a->index < i){ */

    else {/* assert(a->right); */
        return arrayGet(a->right, i);
        
    }

}
    
// Set the i-th element of an array to v.
// No effect if i is out of range.
// Cost: O(log n).
int leftCombine(const Array *);
void arrayFix(Array *, size_t i);
void arraySet(Array *a, size_t i, int v){
        if(a->index == i && a->size == 1){
    /* if(a->index == i){ */
            a->value = v;
            

            /* printf("set index %zu to %d\n", i,v); */
            return;
        } else if(a->right->index > i) {
            /* if (a->left) { */
                a = a->left;
                arraySet(a, i, v);
                /* a->aggregate = leftCombine(a->left); */
                /* printf("set arrayagg %d to %d\n", a->index, a->aggregate); */
        } else {
                a = a->right;
                arraySet(a,i,v);
                /* a->aggregate = arrayCombine(a,i); */
                /* a->aggregate = leftCombine(a->left); */
        }
        arrayFix(a, i);
    

}
void arrayFix(Array *a, size_t i){
    if (a->size == 1){
        return;
    } else if(a->right->index > i){
        a->aggregate = leftCombine(a->left);
        a = a->left;
        arrayFix(a,i);
    } else {
        a = a->right;
        arrayFix(a, i);
    }
}
int leftCombine(const Array *a) {
    if (a->size == 1){
        /* printf("136"); */
        return a->value;
    } else {
        return (a->combine(leftCombine(a->left), leftCombine(a->right)));
    }
    
    
    /* else { */
    /*     if (a->right->index > k) { */
    /*         return leftCombine(a->left,k); */
    /*     } */
        
    /*     /\* printf("140"); *\/ */
    /*     return a->combine(a->left->aggregate, leftCombine(a->right, k)); */
    /* }             */
}
int
arrayCombineIterative(const Array *self, size_t k, int (*combine)(int, int))
{
    int accumulator = arrayGet(self, 0);
    for(int i = 1; i < k; i++) {
        accumulator = combine(accumulator, arrayGet(self, i));
    } 
    return accumulator;
}
// Return the result of aggmmjjregating the first k elements
// of an array in order using the combine function.
// If k is zero or greater than size, returns combination of all elements.
// Cost: O(log n).
int arrayCombine(const Array *a, size_t k) {
    assert(a);
    //TODO maybe take out for testing purposes
    if(k == 0 || k > a->size) {return arrayCombine(a, a->size);}
    /* if (a->index == k){ */
        /* assert(a->value); */
        /* return a->value; */
    /* } */
    /* printf("looking: %zu, index: %d\n", k, a->index); */
    if (a->size == 1){
        /* assert(a->value); */
        /* printf("136"); */
        return a->value;
    }
    else {
        assert(a->right);
        if (a->right->index > k) {
            return arrayCombine(a->left,k);
        }
        
        /* printf("140"); */
        return a->combine(a->aggregate, arrayCombine(a->right, k));
    }            
}
