#include "tree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>




//TODO add input weird handling
//TODO make realloc just double on overflow
/* tree *treeTest() { */
/*     tree *t1 = buildTree(); */
/*     tree *t2 = buildTree(); */
/*     tree *tb = buildTree(); */
    
/*     tb->subTrees = malloc(sizeof(tree *) * 2); */
/*     tb->subTrees[0] = t1; */
/*     tb->subTrees[1] = t2; */
/*     tb->nodes = 2; */
/*     qSortTree(tb); */
/*     return tb; */
/* } */



tree *layerDown(tree *ct) {
  //Moved the buildTree into here to reduce stack usage
   tree *t = malloc(sizeof(tree));
   t->size = 1;
   t->nodes = 0;
   t->subTrees = 0;
   t->parent = ct;
   t->tSize = 1;
   ct->nodes++;
   if(ct->size == 0){ct->size++;}
   if (ct->nodes >= ct->size){
        ct->subTrees = realloc(ct->subTrees, sizeof(tree *) * ct->size * 2);
        ct->size = 2 * ct->size;
    }
   
   ct->subTrees[ct->nodes - 1] = t;
   return readTree(t);
}

tree *layerUp(tree *t) {
    if (t->parent == 0){return (t);}
    t->parent->tSize += t->tSize;
    /* if (t->parent->size == 0){ */
    /* t->parent->size++; */
    /* } */

    
    return readTree(t->parent);
}

tree *readFirst() {
    int input = getchar();
    tree *ct = buildTree();
    assert(input == '[');
    return readTree(ct);
}

tree *readTree(tree *ct) {
    int input = getchar();
    while (input != EOF) {
        switch (input){
            case '[':
                return layerDown(ct);
                break;
            case ']':
                return layerUp(ct);
                break;
            default:
                /* return (layerUp(ct)); */
                
                /* exit(1); */
                if (ct->parent == 0 && ct->size > 0) {return ct;}
                /* return layerUp(ct); */
                return treeExit(ct);
                
 }
    }
    /* if (ct->parent == 0) {return treeExit(ct);}; */
    return ct;
}

tree *treeExit(tree *ct) {
    while(ct->parent != 0) {
        /* ct = layerUp(ct); */
        }
    deleteTree(ct);
    /* } */
    exit(1);
}

tree *buildTree() {
   tree *t = malloc(sizeof(tree));
   //TODO maybe problem with tsize ->3
   t->size = 0;
   t->nodes = 0;
   t->subTrees = 0;
   t->parent = 0;
   t->tSize = 1;
   return t;
}

int cmpTree(const void *t1, const void *t2) {
    /* printf("87\n"); */
    int l = (*((tree **)t1))->tSize;
    int r = (*((tree **)t2))->tSize;
    /* printf("l: %d, r: %d\n", l, r); */
    return(r > l);
}

void qSortTree(tree *t) {
    assert(t);
    /* printf("Tree before:%p \n", t); */
    /* printTree(t); */
    /* printf("\n***"); */
    
    /* printf("91\n"); */
    /* assert(t); */
    if (t->nodes == 0) {return;}
    /* printf("nodes: %d\n", t->nodes); */
    /* printf("nodes123: %d, %d, %d\n", t->subTrees[0]->nodes, t->subTrees[1]->nodes, t->subTrees[2]->nodes); */
    qsort(t->subTrees, t->nodes, sizeof(tree *), cmpTree);
    for (int i = 0; i < t->nodes; i++) {
        /* printf("%d\n",i); */
        qSortTree(t->subTrees[i]);
    }
    /* printf("Tree after:%p \n", t); */
    /* printTree(t); */
    /* printf("\n***"); */
}

void printTree(tree *t) {
  if (t == NULL) {
      printf("109");
      printf("PROABLEM");
      return;
  }
  /* if (t->nodes == 0) { */
      /* printf("[]");  */
 /* }  */
  else {
      putchar('[');
      /* printf("nodes: %d\n", t->nodes); */
      /* if(t->nodes != 0) { */
          for (int i = 0; i < t->nodes; i++) {
              printTree(t->subTrees[i]);
          }
      /* } */
      putchar(']');
  }
}

void deleteTree(tree *t) {
    assert(t);
    /* printf("numNodes \n") */
    if (t->nodes == 0) {
        free(t);
    }
    else {
        for (int i = 0; i < t->nodes; i++) {
            deleteTree(t->subTrees[i]);
            /* free(t->subTrees); */
            /* free(t); */
        }
        free(t->subTrees);
        free(t);
    }
}
