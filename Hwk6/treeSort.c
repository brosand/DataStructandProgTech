#include "treeSort.h"
#include "tree.h"




int main() {
    tree *t =readFirst();
    qSortTree(t);
    printTree(t);
    return 0;
}
