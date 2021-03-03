#include "hdf_host_info.h"
#include "osal_mem.h"
void HdfHostInfoFreeInstance(struct HdfHostInfo *hostInfo)
{
    if (hostInfo != NULL) {
        OsalMemFree(hostInfo);
    }
}
