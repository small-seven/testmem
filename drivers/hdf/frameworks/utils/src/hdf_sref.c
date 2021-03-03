#include "hdf_sref.h"
#include "hdf_log.h"
#define HDF_LOG_TAG hdf_sref
void HdfSRefRelease(struct HdfSRef *sref)
{
    int32_t lockRef;
    if (sref == NULL) {
        HDF_LOGE("Release input sref is null");
        return;
    }
    OsalAtomicDec(&sref->refs);
    lockRef = OsalAtomicRead(&sref->refs);
    if ((lockRef == 0) && (sref->listener != NULL)) {
        struct IHdfSRefListener *listener = sref->listener;
        if (listener->OnLastRelease != NULL) {
            listener->OnLastRelease(sref);
        }
    }
}
