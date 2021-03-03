#include "los_rbtree.h"
#include "los_memory.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
LosRbWalk *LOS_RbCreateWalk(LosRbTree *pstTree)
{
    LosRbNode *pstNode = NULL;
    LosRbWalk *pstWalk = NULL;

    if (NULL == pstTree) {
        return NULL;
    }

    pstNode = LOS_RbFirstNode(pstTree);
    if (NULL == pstNode) {
        return NULL;
    }

    pstWalk = (LosRbWalk *)LOS_MemAlloc(m_aucSysMem0, sizeof(LosRbWalk));
    if (NULL == pstWalk) {
        return NULL;
    }

    LOS_ListAdd(&pstTree->stWalkHead, &pstWalk->stLink);
    pstWalk->pstCurrNode = pstNode;
    pstWalk->pstTree = pstTree;
    return pstWalk;
}
VOID LOS_RbDestroyTree(LosRbTree *pstTree)
{
    LosRbNode *pstNode = NULL;

    if (NULL == pstTree) {
        return;
    }
    if (NULL == pstTree->pfFree) {
        return;
    }

    RB_WALK(pstTree, pstNode, pstWalk)
    {
        OsRbDeleteNode(pstTree, pstNode);
        (VOID)pstTree->pfFree(pstNode);
    }
    RB_WALK_END(pstTree, pstNode, pstWalk);

    OsRbClearTree(pstTree);

    return;
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
