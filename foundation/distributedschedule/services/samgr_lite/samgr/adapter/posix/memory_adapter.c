#include "memory_adapter.h"
#include <stdlib.h>
void *SAMGR_Malloc(uint32 size)
{
    if (size == 0) {
        return NULL;
    }
    return malloc(size);
}
void SAMGR_Free(void *buffer)
{
    if (buffer == NULL) {
        return;
    }
    (void)free(buffer);
}