#include "hm_liteipc.h"
#include "linux/kernel.h"
#include <fs/fs.h>
#include "los_mp.h"
#include "los_mux.h"
#include "los_process_pri.h"
#include "los_spinlock.h"
#include "los_task_pri.h"
#if (LOSCFG_KERNEL_TRACE == YES)
#include "los_trace.h"
#endif
#include "los_vm_map.h"
#include "los_vm_phys.h"
#include "los_vm_page.h"
#include "los_vm_lock.h"
#define USE_TASKID_AS_HANDLE YES
#define USE_MMAP YES
#define IPC_MSG_DATA_SZ_MAX 1024
#define IPC_MSG_OBJECT_NUM_MAX 256
#define LITE_IPC_POOL_NAME "liteipc"
#define LITE_IPC_POOL_PAGE_MAX_NUM 64 /* 256KB */
#define LITE_IPC_POOL_PAGE_DEFAULT_NUM 16 /* 64KB */
#define LITE_IPC_POOL_MAX_SIZE (LITE_IPC_POOL_PAGE_MAX_NUM << PAGE_SHIFT)
#define LITE_IPC_POOL_DEFAULT_SIZE (LITE_IPC_POOL_PAGE_DEFAULT_NUM << PAGE_SHIFT)
#define LITE_IPC_POOL_UVADDR 0x10000000
#define INVAILD_ID (-1)
#define LITEIPC_TIMEOUT_MS 5000UL
#define LITEIPC_TIMEOUT_NS 5000000000ULL
typedef struct {
    LOS_DL_LIST list;
    VOID *ptr;
} IpcUsedNode;
#if (USE_TASKID_AS_HANDLE == YES)
#else
#endif
#define IPC_LOCK(state)       LOS_SpinLockSave(&g_ipcSpin, &(state))
#define IPC_UNLOCK(state)     LOS_SpinUnlockRestore(&g_ipcSpin, state)
#ifndef CONFIG_DISABLE_POLL
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#if (USE_TASKID_AS_HANDLE == YES)
#else
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
LITE_OS_SEC_TEXT STATIC INT32 DoIpcMmap(LosProcessCB *pcb, LosVmMapRegion *region)
{
    UINT32 i;
    INT32 ret = 0;
    PADDR_T pa;
    UINT32 uflags = VM_MAP_REGION_FLAG_PERM_READ | VM_MAP_REGION_FLAG_PERM_USER;
    LosVmPage *vmPage = NULL;
    VADDR_T uva = (VADDR_T)(UINTPTR)pcb->ipcInfo.pool.uvaddr;
    VADDR_T kva = (VADDR_T)(UINTPTR)pcb->ipcInfo.pool.kvaddr;

    (VOID)LOS_MuxAcquire(&pcb->vmSpace->regionMux);

    for (i = 0; i < (region->range.size >> PAGE_SHIFT); i++) {
        pa = LOS_PaddrQuery((VOID *)(UINTPTR)(kva + (i << PAGE_SHIFT)));
        if (pa == 0) {
            PRINT_ERR("%s, %d\n", __FUNCTION__, __LINE__);
            ret = -EINVAL;
            break;
        }
        vmPage = LOS_VmPageGet(pa);
        if (vmPage == NULL) {
            PRINT_ERR("%s, %d\n", __FUNCTION__, __LINE__);
            ret = -EINVAL;
            break;
        }
        STATUS_T err = LOS_ArchMmuMap(&pcb->vmSpace->archMmu, uva + (i << PAGE_SHIFT), pa, 1, uflags);
        if (err < 0) {
            ret = err;
            PRINT_ERR("%s, %d\n", __FUNCTION__, __LINE__);
            break;
        }
        LOS_AtomicInc(&vmPage->refCounts);
    }
    /* if any failure happened, rollback */
    if (i != (region->range.size >> PAGE_SHIFT)) {
        while (i--) {
            pa = LOS_PaddrQuery((VOID *)(UINTPTR)(kva + (i << PAGE_SHIFT)));
            vmPage = LOS_VmPageGet(pa);
            (VOID)LOS_ArchMmuUnmap(&pcb->vmSpace->archMmu, uva + (i << PAGE_SHIFT), 1);
            LOS_PhysPageFree(vmPage);
        }
    }

    (VOID)LOS_MuxRelease(&pcb->vmSpace->regionMux);
    return ret;
}
LITE_OS_SEC_TEXT STATIC int LiteIpcMmap(FAR struct file* filep, LosVmMapRegion *region)
{
    int ret = 0;
    LosVmMapRegion *regionTemp = NULL;
    LosProcessCB *pcb = OsCurrProcessGet();
    if ((region == NULL) || (region->range.size > LITE_IPC_POOL_MAX_SIZE) ||
            (!LOS_IsRegionPermUserReadOnly(region)) || (!LOS_IsRegionFlagPrivateOnly(region))) {
        ret = -EINVAL;
        goto ERROR_REGION_OUT;
    }
    if (IsPoolMapped()) {
        return -EEXIST;
    }
    if (pcb->ipcInfo.pool.uvaddr != NULL) {
        regionTemp = LOS_RegionFind(pcb->vmSpace, (VADDR_T)(UINTPTR)pcb->ipcInfo.pool.uvaddr);
        if (regionTemp != NULL) {
            (VOID)LOS_RegionFree(pcb->vmSpace, regionTemp);
        }
    }
    pcb->ipcInfo.pool.uvaddr = (VOID *)(UINTPTR)region->range.base;
    if (pcb->ipcInfo.pool.kvaddr != NULL) {
        LOS_VFree(pcb->ipcInfo.pool.kvaddr);
        pcb->ipcInfo.pool.kvaddr = NULL;
    }
    /* use vmalloc to alloc phy mem */
    pcb->ipcInfo.pool.kvaddr = LOS_VMalloc(region->range.size);
    if (pcb->ipcInfo.pool.kvaddr == NULL) {
        ret = -ENOMEM;
        goto ERROR_REGION_OUT;
    }
    /* do mmap */
    ret = DoIpcMmap(pcb, region);
    if (ret) {
        goto ERROR_MAP_OUT;
    }
    /* ipc pool init */
    if (LOS_MemInit(pcb->ipcInfo.pool.kvaddr, region->range.size) != LOS_OK) {
        ret = -EINVAL;
        goto ERROR_MAP_OUT;
    }
    pcb->ipcInfo.pool.poolSize = region->range.size;
    return 0;
ERROR_MAP_OUT:
    LOS_VFree(pcb->ipcInfo.pool.kvaddr);
ERROR_REGION_OUT:
    pcb->ipcInfo.pool.uvaddr = NULL;
    pcb->ipcInfo.pool.kvaddr = NULL;
    return ret;
}
LITE_OS_SEC_TEXT STATIC VOID EnableIpcNodeFreeByUser(UINT32 processID, VOID *buf)
{
    UINT32 intSave;
    IpcUsedNode *node = (IpcUsedNode *)malloc(sizeof(IpcUsedNode));
    if (node != NULL) {
        node->ptr = buf;
        IPC_LOCK(intSave);
        LOS_ListAdd(&g_ipcUsedNodelist[processID], &node->list);
        IPC_UNLOCK(intSave);
    }
}
LITE_OS_SEC_TEXT STATIC VOID* LiteIpcNodeAlloc(UINT32 processID, UINT32 size)
{
    VOID *ptr = LOS_MemAlloc(OS_PCB_FROM_PID(processID)->ipcInfo.pool.kvaddr, size);
    PRINT_INFO("LiteIpcNodeAlloc pid:%d, pool:%x buf:%x size:%d\n",
               processID, OS_PCB_FROM_PID(processID)->ipcInfo.pool.kvaddr, ptr, size);
    return ptr;
}
LITE_OS_SEC_TEXT STATIC UINT32 LiteIpcNodeFree(UINT32 processID, VOID *buf)
{
    PRINT_INFO("LiteIpcNodeFree pid:%d, pool:%x buf:%x\n",
               processID, OS_PCB_FROM_PID(processID)->ipcInfo.pool.kvaddr, buf);
    return LOS_MemFree(OS_PCB_FROM_PID(processID)->ipcInfo.pool.kvaddr, buf);
}
#if (USE_TASKID_AS_HANDLE == YES)
#else
#endif
#if (USE_TASKID_AS_HANDLE == YES)
#else
#endif
#if (USE_TASKID_AS_HANDLE == NO)
#endif
LITE_OS_SEC_TEXT VOID LiteIpcRemoveServiceHandle(LosTaskCB *taskCB)
{
    UINT32 j;
#if (USE_TASKID_AS_HANDLE == YES)

    UINT32 intSave;
    LOS_DL_LIST *listHead = NULL;
    LOS_DL_LIST *listNode = NULL;
    IpcListNode *node = NULL;
    UINT32 processID = taskCB->processID;

    listHead = &(taskCB->msgListHead);
    do {
        SCHEDULER_LOCK(intSave);
        if (LOS_ListEmpty(listHead)) {
            SCHEDULER_UNLOCK(intSave);
            break;
        } else {
            listNode = LOS_DL_LIST_FIRST(listHead);
            LOS_ListDelete(listNode);
            node = LOS_DL_LIST_ENTRY(listNode, IpcListNode, listNode);
            SCHEDULER_UNLOCK(intSave);
            (VOID)HandleSpecialObjects(taskCB->taskID, node, TRUE);
            (VOID)LiteIpcNodeFree(processID, (VOID *)node);
        }
    } while (1);

    taskCB->accessMap[processID] = FALSE;
    for (j = 0; j < MAX_SERVICE_NUM; j++) {
        if (taskCB->accessMap[j] == TRUE) {
            taskCB->accessMap[j] = FALSE;
            (VOID)SendDeathMsg(j, taskCB->taskID);
        }
    }
#else
    (VOID)LOS_MuxLock(&g_serviceHandleMapMux, LOS_WAIT_FOREVER);
    for (UINT32 i = 1; i < MAX_SERVICE_NUM; i++) {
        if ((g_serviceHandleMap[i].status != HANDLE_NOT_USED) && (g_serviceHandleMap[i].taskID == taskCB->taskID)) {
            g_serviceHandleMap[i].status = HANDLE_NOT_USED;
            g_serviceHandleMap[i].taskID = INVAILD_ID;
            break;
        }
    }
    (VOID)LOS_MuxUnlock(&g_serviceHandleMapMux);
    /* run deathHandler */
    if (i < MAX_SERVICE_NUM) {
        for (j = 0; j < MAX_SERVICE_NUM; j++) {
            if (taskCB->accessMap[j] == TRUE) {
                (VOID)SendDeathMsg(j, i);
            }
        }
    }
#endif
}
#if (USE_TASKID_AS_HANDLE == YES)
#else
#endif
#if (USE_TASKID_AS_HANDLE == YES)
#else
#endif
#if (USE_TASKID_AS_HANDLE == YES)
#else
#endif
#ifdef LOSCFG_SECURITY_CAPABILITY
#endif
#if (USE_TIMESTAMP == YES)
#endif
#if (USE_TIMESTAMP == YES)
#endif
#if (USE_TIMESTAMP == YES)
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#endif
#if (USE_TIMESTAMP == YES)
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#if (USE_TIMESTAMP == YES)
#else
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
#if (LOSCFG_KERNEL_TRACE == YES)
#endif
