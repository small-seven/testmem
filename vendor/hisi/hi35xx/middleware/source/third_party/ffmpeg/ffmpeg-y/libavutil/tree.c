#include "error.h"
#include "log.h"
#include "mem.h"
#include "tree.h"
typedef struct AVTreeNode {
    struct AVTreeNode *child[2];
    void *elem;
    int state;
} AVTreeNode;
void av_tree_destroy(AVTreeNode *t)
{
    if (t) {
        av_tree_destroy(t->child[0]);
        av_tree_destroy(t->child[1]);
        av_free(t);
    }
}
