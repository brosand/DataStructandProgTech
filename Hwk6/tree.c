#include "tree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



tree *uglyIteration(){
  //Had a pretty recursive version but found out tail recursion is bad in C
  int input = getchar();
  if(input != '[') {exit(1);}
  
  tree *ct = buildTree();
  /* assert(input == '['); */
 
  READTREE: ;
  
  input = getchar();
  while(input != EOF){

    switch (input){

      case '[': ;

        tree *t = buildTree();
        t->parent = ct;
        t->size = 1;
        ct->nodes++;

        if(ct->size == 0){ct->size++;}

        if (ct->nodes >= ct->size){
          ct->subTrees = realloc(ct->subTrees, sizeof(tree *) * ct->size * 2);
          ct->size = 2 * ct->size;
        }

        ct->subTrees[ct->nodes - 1] = t;
        ct = t;

      goto READTREE;
      break;

      case ']':

        if (ct->parent == 0){goto END;}

        ct->parent->tSize += ct->tSize;
        ct = ct->parent;

        goto READTREE;
      break;

      default:

        EXITTREE:

        while(ct->parent != 0) {
          ct->parent->tSize += ct->size;
          ct = ct->parent;
        }

        deleteTree(ct);
        exit(1);
        
    }
  }

  END:

  if (ct->parent != 0){goto EXITTREE;}
  return ct;

  
}

tree *buildTree() {
 tree *t = malloc(sizeof(tree));

 t->size = 0;
 t->nodes = 0;
 t->subTrees = 0;
 t->parent = 0;
 t->tSize = 1;

 return t;
}

int cmpTree(const void *t1, const void *t2) {
  int l = (*((tree **)t1))->tSize;
  int r = (*((tree **)t2))->tSize;

  return(r > l);
}

void qSortTree(tree *t) {
  assert(t);
  qsort(t->subTrees, t->nodes, sizeof(tree *), cmpTree);

  for (int i = 0; i < t->nodes; i++) {
    qSortTree(t->subTrees[i]);
  }
}

void printTree(tree *t) {
  assert(t);

    putchar('[');

    for (int i = 0; i < t->nodes; i++) {
      printTree(t->subTrees[i]);
    }

    putchar(']');

  }

void deleteTree(tree *t) {
  assert(t);

  if (t->nodes == 0) {
    free(t);
  }

  else {
    for (int i = 0; i < t->nodes; i++) {
      deleteTree(t->subTrees[i]);
    }
    
    free(t->subTrees);
    free(t);
  }
}
