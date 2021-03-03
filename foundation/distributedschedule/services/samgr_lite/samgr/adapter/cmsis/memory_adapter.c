#include "memory_adapter.h"
#include <los_memory.h>
void *SAMGR_Malloc(uint32 size)
{
    if (size == 0) {
        return NULL;
    }
    return LOS_MemAlloc(m_aucSysMem0, (UINT32)size);
}
void SAMGR_Free(void *buffer)
{
    if (buffer == NULL) {
        return;
    }
    (void)LOS_MemFree(m_aucSysMem0, buffer);
}