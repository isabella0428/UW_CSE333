#include "bst.h"
#include <stdlib.h>

/* Implement key insert() and lookup() functions */

void insert(int32_t value, treeNodePtr root){
    if(!root)
        return;
    if(value < root->value){
        if(!root->left)
        {
            treeNodePtr n = (treeNodePtr)malloc(sizeof(treeNode));
            n->value = value;
            n->left = n->right = NULL;
            root->left = n;
            return;
        }
        return insert(value, root->left);
    }
    else{
        if (!root->right)
        {
            treeNodePtr n = (treeNodePtr)malloc(sizeof(treeNode));
            n->value = value;
            n->left = n->right = NULL;
            root->right = n;
            return;
        }
        return insert(value, root->right);
    }
}

int lookUp(int32_t value, treeNodePtr root){
    if(!root)
        return 0;
    if(root->value == value)
        return 1;
    else{
        if(value < root->value){
            return lookUp(value, root->left);
        }
        else{
            return lookUp(value, root->right);
        }
    }
}