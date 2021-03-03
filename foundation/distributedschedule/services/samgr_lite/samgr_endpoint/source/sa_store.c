#include "sa_store.h"
#include <ohos_errno.h>
#include <securec.h>
#include "common.h"
#include "memory_adapter.h"
#define GROW_STEP 4
#define MAX_SA_NUM 300
static void FreeTreeNode(SAStore *saStore, ListNode *node)
{
    while (node->info.head != NULL) {
        FeatureNode *freeNode = node->info.head;
        node->info.head = node->info.head->next;
        SAMGR_Free(freeNode);
        saStore->saSize--;
    }
    SAMGR_Free(node);
}