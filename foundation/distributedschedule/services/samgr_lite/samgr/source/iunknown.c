#include "iunknown.h"
#include "common.h"
#define OLD_VERSION 0
int IUNKNOWN_Release(IUnknown *iUnknown)
{
    if (iUnknown == NULL) {
        return EC_INVALID;
    }

    IUnknownEntry *entry = GET_OBJECT(iUnknown, IUnknownEntry, iUnknown);
    int ref = entry->ref - 1;
    if (ref < 0) {
        // The iUnknown is already freed, there is some exception;
    } else {
        if (ref == 0) {
            // Nobody reference to the iUnknown, should delete it.
            // But iUnknown may be global variable, so the default version don`t delete it.
        } else {
            entry->ref = ref;
        }
    }
    return ref;
}