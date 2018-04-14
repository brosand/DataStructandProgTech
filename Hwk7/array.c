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
    int max;
    int value;
    int (*combine)(int, int);
    struct array *left;
    struct array *right;
    
};
Array *arrayCreateR(int (*combine)(int, int), size_t n, size_t k, size_t max);

Array *arrayCreate(int (*combine)(int, int), size_t n){

    Array *a = malloc(sizeof(Array));
    a->max = n;
    a->size = n;
    a->index = n/2;
    a->combine = combine;
    a->aggregate = 0;
    int l = 0;
    if (n%2 != 0){l = 1;}
    
    if(n == 1){
        a->left = a->right = 0;
        return a;
    }
    
    a->left = arrayCreateR(combine, n/2, 0, n);
    a->right = arrayCreateR(combine, n/2 + l, n/2, n);
    if(a->combine(7,9) != 16){
    for (int i = 0; i < n; i++){
        arraySet(a, i, 0);}}
    return a;


}

Array *arrayCreateR(int (*combine)(int, int), size_t n, size_t k, size_t max){
    assert(n!=0);
    Array *a = malloc(sizeof(Array));
    int l = 0;
    if (n%2 != 0){l = 1;}
    a->size = n;
    a->max = max;
    a->index = k;
    a->value = 0;
    a->aggregate = 0;
    a->combine = combine;
    
    if(n == 1){
        a->left = a->right = 0;
        return a;
    }
    a->left = arrayCreateR(combine, n/2, a->index, max);
    a->right = arrayCreateR(combine, n/2 + l, a->index + n/2, max);
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
int arrayGet(const Array *a, size_t i) {
    if (a->max < i) {return 0;}
    if (a->index == i && a->size == 1){return a->value;}
    if(i < 0){return 0;}
    else if (!a->right){return 0;} 
    else if (a->right->index > i){
        if(a->left){
            return arrayGet(a->left, i);
        }
     }

    // else {
        return arrayGet(a->right, i);
        
    // }

}
    
// Set the i-th element of an array to v.
// No effect if i is out of range.
// Cost: O(log n).
int leftCombine(const Array *);
void arraySet(Array *a, size_t i, int v){
    if (i < 0 || i >= a->max){return;}
    if(a->index == i && a->size == 1){
        a->value = v;
        return;
    }
    else if(a->right->index > i) {
        Array *tmp;
        tmp = a;
        a = a->left;
        arraySet(a, i, v);
        tmp->aggregate = leftCombine(tmp->left);
    } else {
        a = a->right;
        arraySet(a,i,v);
    }
    

}
int leftCombine(const Array *a) {
    if (a->size == 1){
        return a->value;
    } else {
        return (a->combine(a->aggregate, leftCombine(a->right)));
    }
}
    
// Return the result of aggmmjjregating the first k elements
// of an array in order using the combine function.
// If k is zero or greater than size, returns combination of all elements.
// Cost: O(log n).
int arrayCombine(const Array *a, size_t k) {
    if (k > a->max) {return arrayCombine(a, a->max);}
    if(k == 0 ) {return arrayCombine(a, a->size);}
    if (a->size == 1){ 
        return a->value;
    }
    else {
        if (a->right->index > (k-1)) {
            return arrayCombine(a->left,k);
        }
        else {
            return a->combine(a->aggregate, arrayCombine(a->right, k));
        }
    }            
}
