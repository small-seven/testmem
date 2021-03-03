#include <string.h>
#include "securec.h"
#include "los_hwi.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "los_membox.h"
#include "los_memory.h"
#include "los_memcheck_pri.h"

#if (LOSCFG_PLATFORM_EXC == YES) || (LOSCFG_BASE_MEM_NODE_INTEGRITY_CHECK == YES)
UINT8 g_memMang[MEM_INFO_SIZE];
#endif

UINT32 LOS_MemboxInit(VOID *boxMem, UINT32 boxSize, UINT32 blkSize)
{
    UINTPTR intSave;
#ifdef LOS_MEMBOX_CHECK
    UINT32 *memCount = (UINT32 *)g_memMang;
    MEM_INFO *memInfo = (MEM_INFO *)(g_memMang + sizeof(UINT32));
    UINT8 loop;
#endif

    if (boxMem == NULL) {
        return OS_ERROR;
    }
#ifdef LOS_MEMBOX_CHECK
#endif
#ifdef LOS_MEMBOX_CHECK
#endif
#ifdef LOS_MEMBOX_CHECK
#endif
