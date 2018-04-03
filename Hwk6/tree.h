#ifndef __TREE_H_
#define __TREE_H_

/* typedef struct { */
/*     int size; */
/*     tree **subTrees; */
/* } tree; */

/* struct Tree { */
    /* int size; */
    /* struct Tree **subTrees; */
/* }; */

struct Tree {
    int size;
    int nodes;
    /* struct Tree *head; */
    /* struct Tree *tail; */
    /* struct Tree *next; */
    struct Tree *parent;
    struct Tree **subTrees;
};

typedef struct Tree tree;


tree *layerDown(tree *ct);

tree *layerUp(tree *t);

tree *readTree(tree *ct);

int cmpTree(const void *t1, const void *t2);

tree *readFirst();

tree *buildTree();

void qSortTree(tree *t);

void printTree(tree *t);

#endif // __TREE_H_
