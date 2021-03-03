#include "hdf_device_token.h"
#include "hdf_object_manager.h"
#include "osal_mem.h"
struct HdfObject *HdfDeviceTokenCreate()
{
    struct HdfDeviceToken *token =
        (struct HdfDeviceToken *)OsalMemCalloc(sizeof(struct HdfDeviceToken));
    if (token != NULL) {
        HdfDeviceTokenConstruct(token);
    }
    return (struct HdfObject *)token;
}
void HdfDeviceTokenRelease(struct HdfObject *object)
{
    struct HdfDeviceToken *deviceToken = (struct HdfDeviceToken *)object;
    if (deviceToken != NULL) {
        OsalMemFree(deviceToken);
    }
}
void HdfDeviceTokenFreeInstance(struct IHdfDeviceToken *token)
{
    if (token != NULL) {
        HdfObjectManagerFreeObject(&token->object);
    }
}
