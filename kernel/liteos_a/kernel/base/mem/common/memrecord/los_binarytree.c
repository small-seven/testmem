#ifdef LOSCFG_MEM_RECORDINFO
#include "los_binarytree_pri.h"
#include "los_typedef.h"
#include "los_typedef.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

UINT32 OsBinTreeInsert(const VOID *node, UINT32 nodeLen, BinNode **leaf,
                       BinNode *(*GetMyBinNode)(UINT32 *nodeID),
                       INT32 (*CompareNode)(const VOID *node1, const VOID *node2))
{
    UINT32 nodeID;
    INT32 result;
    BinNode **currentNode = leaf;

    if (leaf == NULL) {
        return OS_INVALID;
    }
#define BINARYTREE_TASKID_COUNT  11
#define BINARYTREE_REQSIZE_COUNT 4
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#endif
