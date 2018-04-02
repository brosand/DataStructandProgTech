#include "tree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



/*
 *Pseudocode
 * while input not eof
 *
 * if [ ->
 *  buildTree(t, readTree)
 *if ] -?
 * ret buildTree(t)
 * 
 */
tree *layerDown(tree *ct) {
   tree *nt = buildTree();
   nt->parent = ct;
   if(ct->head == NULL){
       ct->head = nt;
       ct->tail = nt;
   }
   else{
      ct->tail->next = nt;
      ct->tail = nt;
      
   }
   ct->size++;
   return readTree(nt);
}

tree *layerUp(tree *t) {
    if (t->parent == NULL){return t;}
    //TODO fix this problem
    return readTree(t->parent);
}

tree *readFirst() {
    int input = getchar();
    /* int layer = 0; */
    tree *ct = buildTree();
    assert(input == '[');
    /* input = getchar(); */
    return readTree(ct);
}

tree *readTree(tree *ct) {
    int input = getchar();
    /* putchar(input); */
    /* int layer = 0; */
    /* tree *ct = buildTree(); */
    /* assert(input == '['); */
    input = getchar();
    while (input != EOF) {
        switch (input){
            case '[':
                /* tree *t = buildTree(); */
                return layerDown(ct);
                /* layer--; */
                break;
            case ']':
                return layerUp(ct);
                /* layer++; */
                break;
        }
    }
    return ct;
}

tree *buildTree() {
   tree *t = malloc(sizeof(tree));
   t->size = 1;
   t->head = NULL;
   t->tail = NULL;
   t->next = NULL;
   t->parent = NULL;
   return t;
}

/* tree *buildTree(int size, tree **subTrees) { */
/*   tree *t = malloc(sizeof(tree)); */
/*   /\* t->subTrees = calloc(sizeof(tree),size); *\/ */
/*   t->subTrees = subTrees; */
/*   t->size = size; */
/*   /\* for (int i = 1; i < size; i++) { *\/ */
/*       /\* tree *newT = buildTree(1); *\/ */
/*       /\* t->subTrees[i] = newT; *\/ */
/*       /\* } *\/ */
/*   return t; */
/* } */



/* void sortTree(tree *t) { */
/*     /\* assert(t->size != 0); *\/ */
/*     if(t->size != 1) { */
/*       for (int i = 0; i < t->size; i++) { */
/*           int j = i; */
/*           while(j > 0 && t->subTrees[j-1] < t->subTrees[j]) { */
/*               tree *tmp = t->subTrees[j-1]; */
/*               t->subTrees[j-1] = t->subTrees[j]; */
/*               t->subTrees[j] = tmp; */
/*               j--; */
/*           } */
/*       } */
/*       for (int i = 0; i < t->size; i++) { */
/*           sortTree(t->subTrees[i]); */
/*       } */
/*     } */
/* } */



/* void mergeSortTree(tree t) { */
    /* tree *t1 = buildTree(t->size); */
    /* tree *t2 = buildTree(t->size); */
    
/* } */





void printTree(tree *t) {
  if (t == NULL) {
      return;
  }
  if (t->size == 1) {
      printf("[]");
 } 
  else {
      putchar('[');
      for (int i = 0; i < t->size; i++) {
          printTree(t->head);
      }
      putchar(']');
  }
}
