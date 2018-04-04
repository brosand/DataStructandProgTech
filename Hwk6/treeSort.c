#include "treeSort.h"
#include "tree.h"




int main() {
    /* tree *tt = treeTest(); */
    tree *t =readFirst();
    qSortTree(t);
    printTree(t);
    deleteTree(t);
    return 0;
}
