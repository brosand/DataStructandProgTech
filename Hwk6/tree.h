#ifndef __TREE_H_
#define __TREE_H_


struct Tree {
    int size;
    int nodes;
    int tSize;
    struct Tree *parent;
    struct Tree **subTrees;
};

typedef struct Tree tree;

int cmpTree(const void *t1, const void *t2);

tree *uglyIteration();

tree *buildTree();

void qSortTree(tree *t);

void printTree(tree *t);

void deleteTree(tree *t);

#endif // __TREE_H_
