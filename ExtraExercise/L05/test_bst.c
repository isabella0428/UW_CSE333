#include "bst.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv){
    treeNodePtr root = (treeNodePtr)malloc(sizeof(treeNode));
    root->value = 0;
    root->left = root->right = NULL;
    insert(1, root);
    insert(-1, root);
    insert(3, root);
    printf("3 is %d the tree", lookUp(3, root) ? "" : "not");
}