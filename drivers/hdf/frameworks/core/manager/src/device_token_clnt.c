#include "device_token_clnt.h"
#include "hdf_device_token.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG device_token_clnt
void DeviceTokenClntFreeInstance(struct DeviceTokenClnt *tokenClnt)
{
    if (tokenClnt != NULL) {
        OsalMemFree(tokenClnt);
    }
}
