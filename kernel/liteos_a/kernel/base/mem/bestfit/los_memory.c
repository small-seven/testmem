#include "los_memory_pri.h"
#include "los_vm_phys.h"
#include "los_vm_boot.h"
#include "los_vm_common.h"
#include "los_vm_filemap.h"
#include "asm/page.h"
#include "los_multipledlinkhead_pri.h"
#include "los_memstat_pri.h"
#include "los_memrecord_pri.h"
#include "los_task_pri.h"
#include "los_exc.h"
#include "los_spinlock.h"
#ifdef LOSCFG_SHELL_EXCINFO
#include "los_excinfo_pri.h"
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define NODEDUMPSIZE  64  /* the dump size of current broken node when memcheck error */
#define COLUMN_NUM    8   /* column num of the output info of mem node */
#define MEM_POOL_EXPAND_ENABLE  1
#define MEM_POOL_EXPAND_DISABLE 0
typedef struct {
    VOID *pool;      /* Starting address of a memory pool */
    UINT32 poolSize; /* Memory pool size */
    UINT32 flag;     /* Whether the memory pool supports expansion */
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
    UINT32 poolWaterLine;   /* Maximum usage size in a memory pool */
    UINT32 poolCurUsedSize; /* Current usage size in a memory pool */
#endif
#ifdef LOSCFG_MEM_MUL_POOL
    VOID *nextPool;
#endif
} LosMemPoolInfo;
typedef struct {
    LOS_DL_LIST freeNodeInfo;         /* Free memory node */
    struct tagLosMemDynNode *preNode; /* Pointer to the previous memory node */

#ifdef LOSCFG_MEM_HEAD_BACKUP
    UINT32 gapSize;
    UINTPTR checksum; /* magic = xor checksum */
#endif

#ifdef LOSCFG_MEM_RECORDINFO
    UINT32 originSize;
#ifdef LOSCFG_AARCH64
    UINT32 reserve1; /* 64-bit alignment */
#endif
#endif

#ifdef LOSCFG_MEM_LEAKCHECK
    UINTPTR linkReg[LOS_RECORD_LR_CNT];
#endif

#ifdef LOSCFG_AARCH64
    UINT32 reserve2; /* 64-bit alignment */
#endif
    /* Size and flag of the current node (the high two bits represent a flag,and the rest bits specify the size) */
    UINT32 sizeAndFlag;
} LosMemCtlNode;
typedef struct tagLosMemDynNode {
#ifdef LOSCFG_MEM_HEAD_BACKUP
    LosMemCtlNode backupNode;
#endif
    LosMemCtlNode selfNode;
} LosMemDynNode;
#ifdef LOSCFG_MEM_MUL_POOL
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#define OS_MEM_TASKID_SET(node, ID) do {                                                  \
#else
#define OS_MEM_TASKID_SET(node, ID) do {                                                  \
#endif
#define OS_MEM_TASKID_GET(node) ((UINTPTR)(((LosMemDynNode *)(node))->selfNode.freeNodeInfo.pstNext) & 0xffffU)
#ifdef LOSCFG_MEM_MUL_MODULE
#define BITS_NUM_OF_TYPE_SHORT    16
#ifdef LOSCFG_MEM_HEAD_BACKUP
#define OS_MEM_MODID_SET(node, ID) do {                                                   \
#else
#define OS_MEM_MODID_SET(node, ID) do {                                                   \
#endif
#define OS_MEM_MODID_GET(node) \
#endif
#define OS_MEM_ALIGN(p, alignSize) (((UINTPTR)(p) + (alignSize) - 1) & ~((UINTPTR)((alignSize) - 1)))
#define OS_MEM_NODE_HEAD_SIZE      sizeof(LosMemDynNode)
#define OS_MEM_MIN_POOL_SIZE       (OS_DLNK_HEAD_SIZE + (2 * OS_MEM_NODE_HEAD_SIZE) + sizeof(LosMemPoolInfo))
#define IS_POW_TWO(value)          ((((UINTPTR)(value)) & ((UINTPTR)(value) - 1)) == 0)
#define POOL_ADDR_ALIGNSIZE        64
#ifdef LOSCFG_AARCH64
#define OS_MEM_ALIGN_SIZE 8
#else
#define OS_MEM_ALIGN_SIZE 4
#endif
#define OS_MEM_NODE_USED_FLAG             0x80000000U
#define OS_MEM_NODE_ALIGNED_FLAG          0x40000000U
#define OS_MEM_NODE_ALIGNED_AND_USED_FLAG (OS_MEM_NODE_USED_FLAG | OS_MEM_NODE_ALIGNED_FLAG)
#define OS_MEM_NODE_GET_ALIGNED_FLAG(sizeAndFlag) \
#define OS_MEM_NODE_SET_ALIGNED_FLAG(sizeAndFlag) \
#define OS_MEM_NODE_GET_ALIGNED_GAPSIZE(sizeAndFlag) \
#define OS_MEM_NODE_GET_USED_FLAG(sizeAndFlag) \
#define OS_MEM_NODE_SET_USED_FLAG(sizeAndFlag) \
#define OS_MEM_NODE_GET_SIZE(sizeAndFlag) \
#define OS_MEM_HEAD(pool, size) \
#define OS_MEM_HEAD_ADDR(pool) \
#define OS_MEM_NEXT_NODE(node) \
#define OS_MEM_FIRST_NODE(pool) \
#define OS_MEM_END_NODE(pool, size) \
#define OS_MEM_MIDDLE_ADDR_OPEN_END(startAddr, middleAddr, endAddr) \
#define OS_MEM_MIDDLE_ADDR(startAddr, middleAddr, endAddr) \
#define OS_MEM_SET_MAGIC(value) \
#define OS_MEM_MAGIC_VALID(value) \
#ifdef LOSCFG_BASE_MEM_NODE_SIZE_CHECK
#endif
#ifdef LOSCFG_MEM_MUL_MODULE
#endif
#ifdef LOSCFG_BASE_MEM_NODE_SIZE_CHECK
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#define CHECKSUM_MAGICNUM    0xDEADBEEF
#define OS_MEM_NODE_CHECKSUN_CALCULATE(ctlNode)    \
#ifdef LOSCFG_MEM_MUL_MODULE
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#else  /* without LOSCFG_MEM_HEAD_BACKUP */
#endif
#ifdef LOSCFG_EXC_INTERACTION
#endif
#ifndef LOSCFG_EXC_INTERACTION
#endif
#ifdef LOSCFG_MEM_LEAKCHECK
#ifdef __LP64__
#else
#endif
#endif
#define OS_CHECK_NULL_RETURN(param) do {              \
STATIC INLINE LosMemDynNode *OsMemFindSuitableFreeBlock(VOID *pool, UINT32 allocSize)
{
    LOS_DL_LIST *listNodeHead = NULL;
    LosMemDynNode *tmpNode = NULL;
    UINT32 maxCount = (LOS_MemPoolSizeGet(pool) / allocSize) << 1;
    UINT32 count;
#ifdef LOSCFG_MEM_HEAD_BACKUP
    UINT32 ret = LOS_OK;
#endif
    for (listNodeHead = OS_MEM_HEAD(pool, allocSize); listNodeHead != NULL;
         listNodeHead = OsDLnkNextMultiHead(OS_MEM_HEAD_ADDR(pool), listNodeHead)) {
        count = 0;
        LOS_DL_LIST_FOR_EACH_ENTRY(tmpNode, listNodeHead, LosMemDynNode, selfNode.freeNodeInfo) {
            if (count++ >= maxCount) {
                PRINT_ERR("[%s:%d]node: execute too much time\n", __FUNCTION__, __LINE__);
                break;
            }

#ifdef LOSCFG_MEM_HEAD_BACKUP
            if (!OsMemChecksumVerify(&tmpNode->selfNode)) {
                PRINT_ERR("[%s]: the node information of current node is bad !!\n", __FUNCTION__);
                OsMemDispCtlNode(&tmpNode->selfNode);
                ret = OsMemBackupRestore(pool, tmpNode);
            }
            if (ret != LOS_OK) {
                break;
            }
#endif

            if (((UINTPTR)tmpNode & (OS_MEM_ALIGN_SIZE - 1)) != 0) {
                LOS_Panic("[%s:%d]Mem node data error:OS_MEM_HEAD_ADDR(pool)=%p, listNodeHead:%p,"
                          "allocSize=%u, tmpNode=%p\n",
                          __FUNCTION__, __LINE__, OS_MEM_HEAD_ADDR(pool), listNodeHead, allocSize, tmpNode);
                break;
            }
            if (tmpNode->selfNode.sizeAndFlag >= allocSize) {
                return tmpNode;
            }
        }
    }

    return NULL;
}
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_MEM_LEAKCHECK
#endif
#ifdef LOS_DLNK_SAFE_CHECK
#elif defined(LOS_DLNK_SIMPLE_CHECK)
#else
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_MEM_LEAKCHECK
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_MEM_LEAKCHECK
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#ifdef LOSCFG_SHELL_EXCINFO
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_MEM_LEAKCHECK
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK
#else
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOSCFG_MEM_LEAKCHECK
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_MEM_LEAKCHECK
#endif
#ifdef LOSCFG_MEM_MUL_POOL
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_MEM_MUL_POOL
#endif
#ifdef LOSCFG_MEM_MUL_POOL
#endif
#ifdef LOSCFG_MEM_MUL_POOL
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifndef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#else
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#else
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_MEM_RECORDINFO
#endif
#ifdef LOSCFG_EXC_INTERACTION
#endif
#ifdef LOSCFG_MEM_HEAD_BACKUP
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#else
#endif
#if defined(OS_MEM_WATERLINE) && (OS_MEM_WATERLINE == YES)
#endif
#ifdef LOSCFG_MEM_LEAKCHECK
#ifdef __LP64__
#else
#endif
#ifdef __LP64__
#else
#endif
#ifdef __LP64__
#else
#endif
#ifdef __LP64__
#else
#endif
#endif
#ifdef LOSCFG_BASE_MEM_NODE_SIZE_CHECK
#ifdef LOSCFG_EXC_INTERACTION
#endif
#ifdef LOSCFG_EXC_INTERACTION
#endif
#endif /* LOSCFG_BASE_MEM_NODE_SIZE_CHECK */
#ifdef LOSCFG_MEM_MUL_MODULE
UINT32 LOS_MemMfree(VOID *pool, VOID *ptr, UINT32 moduleID)
{
    UINT32 intSave;
    UINT32 ret;
    UINT32 size;
    LosMemDynNode *node = NULL;

    if ((OsMemModCheck(moduleID) == LOS_NOK) || (ptr == NULL) || (pool == NULL)) {
        return LOS_NOK;
    }

    node = (LosMemDynNode *)OsMemPtrToNode(ptr);
    if (node == NULL) {
        return LOS_NOK;
    }

    size = OS_MEM_NODE_GET_SIZE(node->selfNode.sizeAndFlag);

    if (moduleID != OS_MEM_MODID_GET(node)) {
        PRINT_ERR("node[%p] alloced in module %lu, but free in module %u\n node's taskID: 0x%x\n",
                  ptr, OS_MEM_MODID_GET(node), moduleID, OS_MEM_TASKID_GET(node));
        moduleID = OS_MEM_MODID_GET(node);
    }

    ret = LOS_MemFree(pool, ptr);
    if (ret == LOS_OK) {
        MEM_LOCK(intSave);
        g_moduleMemUsedSize[moduleID] -= size;
        MEM_UNLOCK(intSave);
    }
    return ret;
}
VOID *LOS_MemMrealloc(VOID *pool, VOID *ptr, UINT32 size, UINT32 moduleID)
{
    VOID *newPtr = NULL;
    UINT32 oldNodeSize;
    UINT32 intSave;
    LosMemDynNode *node = NULL;
    UINT32 oldModuleID = moduleID;

    if ((OsMemModCheck(moduleID) == LOS_NOK) || (pool == NULL)) {
        return NULL;
    }

    if (ptr == NULL) {
        return LOS_MemMalloc(pool, size, moduleID);
    }

    node = (LosMemDynNode *)OsMemPtrToNode(ptr);
    if (node == NULL) {
        return NULL;
    }

    if (moduleID != OS_MEM_MODID_GET(node)) {
        PRINT_ERR("a node[%p] alloced in module %lu, but realloc in module %u\n node's taskID: %lu\n",
                  ptr, OS_MEM_MODID_GET(node), moduleID, OS_MEM_TASKID_GET(node));
        oldModuleID = OS_MEM_MODID_GET(node);
    }

    if (size == 0) {
        (VOID)LOS_MemMfree(pool, ptr, oldModuleID);
        return NULL;
    }

    oldNodeSize = OsMemNodeSizeGet(ptr);
    newPtr = LOS_MemRealloc(pool, ptr, size);
    if (newPtr != NULL) {
        MEM_LOCK(intSave);
        g_moduleMemUsedSize[moduleID] += OsMemNodeSizeGet(newPtr);
        g_moduleMemUsedSize[oldModuleID] -= oldNodeSize;
        node = (LosMemDynNode *)OsMemPtrToNode(newPtr);
        OS_MEM_MODID_SET(node, moduleID);
        MEM_UNLOCK(intSave);
    }
    return newPtr;
}
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
