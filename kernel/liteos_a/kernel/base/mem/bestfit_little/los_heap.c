#include "string.h"
#include "securec.h"
#include "los_hwi.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "los_heap_pri.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

static UINT32 g_memAllocCount = 0;
static UINT32 g_memFreeCount = 0;

#if (LOSCFG_HEAP_MEMORY_PEAK_STATISTICS == YES)
static UINT32 g_memCurHeapUsed = 0;
static UINT32 g_memMaxHeapUsed = 0;
#endif

#define HEAP_CAST(t, exp) ((t)(exp))
#define HEAP_ALIGN 4
#define HEAP_TAIL_NODE_SIZE_THRESHOLD   1024

/*
 * Description : look up the next memory node according to one memory node in the memory block list.
 * Input       : struct LosHeapManager *heapMan --- Pointer to the manager,to distinguish heap
 *               struct LosHeapNode *node --- Size of memory in bytes to allocate
 * Return      : Pointer to next memory node
 */
struct LosHeapNode* OsHeapPrvGetNext(struct LosHeapManager *heapMan, struct LosHeapNode *node)
{
    return (heapMan->tail == node) ? NULL : (struct LosHeapNode *)(UINTPTR)(node->data + node->size);
}
#if (LOSCFG_HEAP_MEMORY_PEAK_STATISTICS == YES)
#endif
#if (LOSCFG_HEAP_MEMORY_PEAK_STATISTICS == YES)
#endif
#if (LOSCFG_HEAP_MEMORY_PEAK_STATISTICS == YES)
#endif
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
