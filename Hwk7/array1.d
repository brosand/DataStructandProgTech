#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"
#define DIV (1)

// Create a new array holding n values, all initially 0.
// Behavior is undefined if n == 0.
// Cost: O(n).


struct array {
    size_t size;
    int aggregate;
    int index;
    int value;
    struct array *left;
    struct array *right;
    
};
Array *arrayCreateR(int (*combine)(int, int), size_t n, size_t k);

Array *arrayCreate(int (*combine)(int, int), size_t n){

    Array *a = malloc(sizeof(Array));

    a->size = n;
    a->index = n/2;
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

int arrayGet(const Array *a, size_t i) {
    if (a->index == i){return a->value;}
    /* printf("found index: %d, looking for: %zu\n", a->index, i); */
    assert(a);
    if (a->right->index > i){
        if(a->left){
            return arrayGet(a->left, i);
        }
        assert(0);
        return 1;
     }

    else {/* assert(a->right); */
        return arrayGet(a->right, i);
     }
    
     
}


// Set the i-th element of an array to v.
// No effect if i is out of range.
// Cost: O(log n).

void arraySet(Array *a, size_t i, int v){
    if(a->index == i){a->value = v;
        return;}
        else if(a->right->index > i) {
            /* if (a->left) { */
                a = a->left;
                arraySet(a, i, v);
              
            }
         else {
            /* if(a->right) { */
                a = a->right;
            /* } else 
            }
        /* } */
        
    }
    printf("size: %zu",a->size);
   /* a->value = v;  */
   /* if(a->right->index == i){a->right->value = v;} */
   /* else if(a->left->index == i) {a->left->value = v;} */
    
}

// Return the result of aggmmjjregating the first k elements
// of an array in order using the combine function.
// If k is zero or greater than size, returns combination of all elements.
// Cost: O(log n).
int arrayCombine(const Array *a, size_t k) {
    return arrayGet(a,k);
    
    if (a->size == 1){return a->value;}
                
                      
    return arrayCombine(a->aggregate, k)
    
    return arrayPull(a,k)->aggregate;mak
    
    
    
    
    
    
    return 23;
    /* int agg = arrayGet(a,0); */
    /* if (a->size < k || k == 0) {k = a->size;}; */
    /* int n = k/DIV; */
    /* int p = k%DIV; */
    
    /* int t = a->itemsDIV[0]; */
    /* for (int i = 1; i < n * p; i++) { */
    /*     t = a->combine(t, a->itemsDIV[i]); */
    /* } */
    /* if (n==0) { */
    /*     t = arrayGet(a,k); */
    /*     p++; */
    /* } */
    /* /\* else {p++;} *\/ */
    
    /* int agg = a->combine(t, arrayGet(a, n*DIV + p)); */
    /* /\* for (int i = 1; i < k; i++) { *\/ */
    /*     /\* agg = (a->combine(agg, arrayGet(a,i))); *\/ */
    /* /\* } *\/ */
    /* for (int i = n*DIV+p+1; i < k; i++) { */
    /*     agg = a->combine(agg, arrayGet(a, i)); */
    /* } */
    
    /* return agg; */
    
}
