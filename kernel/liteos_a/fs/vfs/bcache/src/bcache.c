#include "bcache.h"
#include "assert.h"
#include "stdlib.h"
#include "linux/delay.h"
#include "disk_pri.h"
#include "fs_other.h"
#include "user_copy.h"
#undef HALARC_ALIGNMENT
#define DMA_ALLGN          64
#define HALARC_ALIGNMENT   DMA_ALLGN
#define BCACHE_MAGIC_NUM   20132016
#define BCACHE_STATCK_SIZE 0x3000
#define ASYNC_EVENT_BIT    0x01
#ifdef DEBUG
#define D(args) printf(args)
#else
#define D(args)
#endif
#ifdef LOSCFG_FS_FAT_CACHE_SYNC_THREAD
#endif
static inline VOID FreeBlock(OsBcache *bc, OsBcacheBlock *block)
{
    block->used = FALSE;
    LOS_ListAdd(&bc->freeListHead, &block->listNode);
}
static OsBcacheBlock *AllocNewBlock(OsBcache *bc, BOOL read, UINT64 num)
{
    OsBcacheBlock *last = NULL;
    OsBcacheBlock *prefer = NULL;

    if (read) { /* read */
        return GetSlowBlock(bc, TRUE);
    }

    /* fallback, this may happen when the block previously flushed, use read buffer */
    if (bc->nBlock && num < GetMinWriteNum(bc)) {
        return GetSlowBlock(bc, TRUE);
    }

    last = RbFindBlock(bc, num - 1);  /* num=0 is ok */
    if (last == NULL || last->readBuff) {
        return GetBaseBlock(bc);      /* new block */
    }

    prefer = last + 1;
    if (prefer > bc->wEnd) {
        prefer = bc->wStart;
    }

    /* this is a sync thread synced block! */
    if (prefer->used && !prefer->modified) {
        prefer->used = FALSE;
        DelBlock(bc, prefer);
    }

    if (prefer->used) {
        MergeSyncBlocks(bc, prefer);
    }

    if (prefer->used) {
        BcacheSyncBlock(bc, prefer);
        DelBlock(bc, prefer);
    }

    prefer->used = TRUE;
    LOS_ListDelete(&prefer->listNode); /* del from free list */

    return prefer;
}
INT32 BlockCacheDrvCreate(VOID *handle,
                          UINT8 *memStart,
                          UINT32 memSize,
                          UINT32 blockSize,
                          OsBcache *bc)
{
    INT32 ret;
    bc->priv = handle;
    bc->breadFun = DrvBread;
    bc->bwriteFun = DrvBwrite;

    ret = BcacheInitCache(bc, memStart, memSize, blockSize);
    if (ret != ENOERR) {
        return ret;
    }

    if (pthread_mutex_init(&bc->bcacheMutex, NULL) != ENOERR) {
        return VFS_ERROR;
    }
    bc->bcacheMutex.attr.type = PTHREAD_MUTEX_RECURSIVE;

    return ENOERR;
}
#ifdef LOSCFG_FS_FAT_CACHE
#else
#endif
#ifdef LOSCFG_FS_FAT_CACHE
#else
#endif
#ifdef LOSCFG_FS_FAT_CACHE_SYNC_THREAD
VOID BcacheSyncThreadDeinit(const OsBcache *bc)
{
    if (bc != NULL) {
        if (LOS_TaskDelete(bc->syncTaskId) != ENOERR) {
            PRINT_ERR("Bcache sync task delete failed in %s, %d\n", __FUNCTION__, __LINE__);
        }
    }
}
#endif
VOID BlockCacheDeinit(OsBcache *bcache)
{
    if (bcache != NULL) {
        (VOID)pthread_mutex_destroy(&bcache->bcacheMutex);
        free(bcache->memStart);
        bcache->memStart = NULL;
        free(bcache->rwBuffer);
        bcache->rwBuffer = NULL;
        free(bcache);
    }
}
UINT32 BcacheAsyncPrereadDeinit(OsBcache *bc)
{
    UINT32 ret = LOS_NOK;

    if (bc != NULL) {
        ret = LOS_TaskDelete(bc->prereadTaskId);
        if (ret != ENOERR) {
            PRINT_ERR("Bcache async task delete failed in %s, %d\n", __FUNCTION__, __LINE__);
        }

        ret = LOS_EventDestroy(&bc->bcacheEvent);
        if (ret != ENOERR) {
            PRINT_ERR("Async event destroy failed in %s, %d\n", __FUNCTION__, __LINE__);
            return ret;
        }
    }

    return ret;
}
