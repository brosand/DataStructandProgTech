#include "tree.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>




//TODO add input weird handling
//TODO make realloc just double on overflow
tree *treeTest() {
    tree *t1 = buildTree();
    tree *t2 = buildTree();
    tree *tb = buildTree();
    
    tb->subTrees = malloc(sizeof(tree *) * 2);
    tb->subTrees[0] = t1;
    tb->subTrees[1] = t2;
    tb->nodes = 2;
    qSortTree(tb);
    return tb;
}

tree *layerDown(tree *ct) {
   tree *nt = buildTree();
   nt->parent = ct;
   /* if(ct->head == NULL){ */
       /* ct->head = nt; */
       /* ct->tail = nt; */
   /* } */
   /* else{ */
      /* ct->tail->next = nt; */
      /* ct->tail = nt; */
      
   /* } */
   /* ct->size++; */
   return readTree(nt);
}

tree *layerUp(tree *t) {
    /* t->subTrees = malloc(sizeof(tree) * (t->size -1)); */
    if (t->parent == 0){return readTree(t);}
    /* t->parent->size++; */
    t->parent->nodes++;
    /* if(!(t->parent->subTrees)){ */
        /* t->parent->subTrees = malloc(t->parent->nodes * sizeof(tree *)); */
    /* }else { */
    if (t->parent->nodes >= t->parent->size){
        t->parent->subTrees = realloc(t->parent->subTrees, sizeof(tree *) * t->parent->size * 2);
        t->parent->size = 2 * t->parent->size;
    }
    /* printf("nodes %d\r",t->parent->size); */
    /* printf("n %d\n", t->parent->nodes); */
    t->parent->subTrees[t->parent->nodes - 1] = t;
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
    /* putchar(input); */
    /* int layer = 0; */
    /* tree *ct = buildTree(); */
    /* assert(input == '['); */
    /* input = getchar(); */
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
            default:
                /* exit(1); */
                return layerUp(ct);
 }
    }
    return ct;
}

tree *buildTree() {
   tree *t = malloc(sizeof(tree));
   //TODO maybe problem with tsize ->3
   t->size = 1;
   t->nodes = 0;
   t->subTrees = 0;
   t->parent = 0;
   return t;
}

int cmpTree(const void *t1, const void *t2) {
    /* printf("87\n"); */
    int l = (*((tree **)t1))->nodes;
    int r = (*((tree **)t2))->nodes;
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
