#include <stdint.h>

typedef struct treeNode{
    int32_t value;
    struct treeNode* left;
    struct treeNode* right;
}treeNode, *treeNodePtr;

/* Insert value into binary search tree */
void insert(int32_t value, treeNodePtr root);

/* Look up if the value is in the binary search tree */
int lookUp(int32_t value, treeNodePtr root);
