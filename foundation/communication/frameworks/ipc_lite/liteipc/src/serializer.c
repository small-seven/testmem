#include "serializer.h"
#include "securec.h"
#include "stdlib.h"
#include "string.h"
#include "liteipc.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define MAX_IO_SIZE 2048UL
#define MAX_OBJ_NUM 32UL
#define MAX_DATA_BUFF_SIZE 65536UL
#define IPC_IO_INITIALIZED 0x01 /* need to  */
#define IPC_IO_OVERFLOW    0x02 /* run out of space */
#define ALIGN_SZ 4
#define IPC_IO_ALIGN(sz) (((sz) + ALIGN_SZ - 1) & (~(ALIGN_SZ - 1)))
#define IPC_IO_RETURN_IF_FAIL(value)                                      \
typedef struct {
    NDK_DL_LIST list;
    BuffPtr ptr;
    IpcIoPtrFree ptrFree;
} IpcPtrNode;
void IpcIoPushDataBuffWithFree(IpcIo* io, const BuffPtr* dataBuff, IpcIoPtrFree ipcIoFree)
{
    IpcIoPushDataBuff(io, dataBuff);
    if ((ipcIoFree != NULL) && IpcIoAvailable(io)) {
        IpcPtrNode* node = malloc(sizeof(IpcPtrNode));
        if (node == NULL) {
            io->flag |= IPC_IO_OVERFLOW;
            return;
        }
        node->ptr = *dataBuff;
        node->ptrFree = ipcIoFree;
        NDK_ListAdd(&io->ptrFreeList, &node->list);
    }
}
void IpcIoFreeDataBuff(IpcIo* io)
{
    IpcPtrNode* node = NULL;
    if ((io == NULL) || (io->ptrFreeList.pstNext == NULL) || (io->ptrFreeList.pstPrev == NULL)) {
        return;
    }
    while (!NDK_ListEmpty(&io->ptrFreeList)) {
        node = NDK_DL_LIST_ENTRY(io->ptrFreeList.pstNext, IpcPtrNode, list);
        if (node->ptrFree != NULL && node->ptr.buff != NULL) {
            node->ptrFree(node->ptr.buff);
        }
        NDK_ListDelete(&node->list);
        free(node);
    }
}
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
