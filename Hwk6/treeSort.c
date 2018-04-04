#include "treeSort.h"
#include "tree.h"




int main() {
    /* tree *tt = treeTest(); */
    tree *t =uglyIteration();
    qSortTree(t);
    printTree(t);
    deleteTree(t);
    return 0;
}
