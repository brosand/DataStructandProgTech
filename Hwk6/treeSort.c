#include "treeSort.h"
#include "tree.h"




int main() {
    /* tree *tt = treeTest(); */
    tree *t =readFirst();
    qSortTree(t);
    printTree(t);
    return 0;
}
