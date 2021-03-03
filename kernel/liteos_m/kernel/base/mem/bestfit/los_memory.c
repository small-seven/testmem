#include "securec.h"
#include "los_memory_pri.h"
#include "los_memstat_pri.h"
#include "los_multipledlinkhead_pri.h"
#include "los_task_pri.h"
#include "los_exc.h"
#include "los_printf.h"
#ifdef LOS_MEM_LEAK_CHECK
#include "los_membox_pri.h"
#endif
#if (LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK == YES)
#include "los_memcheck_pri.h"
#endif
#ifdef LOSCFG_LIB_LIBC
#include "string.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (LOSCFG_MEM_MUL_POOL == YES)
#endif
#if (LOSCFG_BASE_CORE_TASKSTACK_INDEPENDENT == YES)
#endif
#ifdef OS_MEM_CHECK_DEBUG
#endif
#ifdef LOS_MEM_LEAK_CHECK
#endif
#ifdef LOSCFG_MEM_MUL_MODULE
#endif
#if (LOSCFG_BASE_CORE_TASKSTACK_INDEPENDENT == YES)
#endif
#if OS_SYS_NOCACHEMEM_SIZE
#endif
STATIC_INLINE LosMemDynNode *OsMemFindSuitableFreeBlock(VOID *pool, UINT32 allocSize)
{
    LOS_DL_LIST *listHead = (LOS_DL_LIST *)NULL;

    for (listHead = OS_MEM_HEAD(pool, allocSize); listHead != NULL;
         listHead = OS_DLNK_NEXT_HEAD(OS_MEM_HEAD_ADDR(pool), listHead)) {
        LosMemDynNode *tmpNode = (LosMemDynNode *)NULL;
        LOS_DL_LIST_FOR_EACH_ENTRY(tmpNode, listHead, LosMemDynNode, freeNodeInfo) {
            if (tmpNode->sizeAndFlag >= allocSize) {
                return tmpNode;
            }
        }
    }

    return (LosMemDynNode *)NULL;
}
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOS_DLNK_SAFE_CHECK
#elif defined(LOS_DLNK_SIMPLE_CHECK)
#else
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef OS_MEM_ENABLE_ALLOC_CHECK
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#if (LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK == YES)
#endif
#if (LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK == YES)
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#if (LOSCFG_MEM_MUL_POOL == YES)
#endif
#if (LOSCFG_MEM_MUL_POOL == YES)
#endif
#ifdef LOS_MEM_LEAK_CHECK
#endif
#ifdef LOS_MEM_LEAK_CHECK
#endif
#ifdef LOS_MEM_LEAK_CHECK
#endif
#ifdef LOS_MEM_LEAK_CHECK
#endif
#ifdef LOS_MEM_LEAK_CHECK
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#else
#endif
#ifdef OS_MEM_CHECK_DEBUG
#endif /* OS_MEM_CHECK_DEBUG */
#ifdef OS_MEM_CHECK_DEBUG
#endif
#ifdef LOSCFG_MEM_MUL_MODULE
UINT32 LOS_MemMfree(VOID *pool, VOID *ptr, UINT32 module)
{
    UINTPTR intSave;
    UINT32 ret;
    UINT32 size;

    if ((OsMemModCheck(module) == LOS_NOK) || (ptr == NULL)) {
        return LOS_NOK;
    }

    size = OsMemNodeSizeGet(ptr);

    if (module != OS_MEM_MODID_GET(OsMemPtrToNode(ptr))) {
        PRINT_ERR("node[%p] alloced in module %d, but free in module %d\n node's taskID: 0x%x\n",
                  ptr, OS_MEM_MODID_GET(OsMemPtrToNode(ptr)), module, OS_MEM_TASKID_GET(OsMemPtrToNode(ptr)));
    }

    ret = LOS_MemFree(pool, ptr);
    if (ret == LOS_OK) {
        intSave = LOS_IntLock();
        g_memInfo[module] -= size;
        LOS_IntRestore(intSave);
    }
    return ret;
}
VOID *LOS_MemMrealloc(VOID *pool, VOID *ptr, UINT32 size, UINT32 module)
{
    VOID *newPtr = NULL;
    UINT32 oldSize;
    UINTPTR intSave;

    if (OsMemModCheck(module) == LOS_NOK) {
        return NULL;
    }

    if (ptr == NULL) {
        return LOS_MemMalloc(pool, size, module);
    }

    if (module != OS_MEM_MODID_GET(OsMemPtrToNode(ptr))) {
        PRINT_ERR("a node[%p] alloced in module %d, but realloc in module %d\n node's taskID: %d\n",
                  ptr, OS_MEM_MODID_GET(OsMemPtrToNode(ptr)), module, OS_MEM_TASKID_GET(OsMemPtrToNode(ptr)));
    }

    if (size == 0) {
        if (LOS_MemMfree(pool, ptr, module) != LOS_OK) {
            PRINT_ERR("Mem Free Failed!\n");
        }
        return NULL;
    }

    oldSize = OsMemNodeSizeGet(ptr);
    newPtr = LOS_MemRealloc(pool, ptr, size);
    if (newPtr != NULL) {
        intSave = LOS_IntLock();
        g_memInfo[module] += OsMemNodeSizeGet(newPtr);
        g_memInfo[module] -= oldSize;
        OS_MEM_MODID_SET(OsMemPtrToNode(newPtr), module);
        LOS_IntRestore(intSave);
    }
    return newPtr;
}
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
