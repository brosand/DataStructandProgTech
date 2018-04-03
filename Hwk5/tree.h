#ifndef __TREE_H_
#define __TREE_H_


typedef struct Tree {
    int size;
    /* tree *head; */
    /* tree *tail; */
    tree *subTrees;
} tree;


tree buildTree();

void sortTree(tree t);

void printTree(tree t);



#endif // __TREE_H_
