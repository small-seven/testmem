#include "hdf_attribute_manager.h"
#include <string.h>
#include "hcs_blob_if.h"
#include "hcs_parser.h"
#include "hcs_tree_if.h"
#include "hdf_device_info.h"
#include "hdf_host_info.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define ATTR_HOST_NAME "hostName"
#define ATTR_DEV_POLICY "policy"
#define ATTR_DEV_PRIORITY "priority"
#define ATTR_DEV_PRELOAD "preload"
#define ATTR_DEV_PERMISSION "permission"
#define ATTR_DEV_MODULENAME "moduleName"
#define ATTR_DEV_SVCNAME "serviceName"
#define ATTR_DEV_MATCHATTR "deviceMatchAttr"
#define MANAGER_NODE_MATCH_ATTR "hdf_manager"
void ReleaseHcsTree(void)
{
    OsalMemFree(g_hcsTreeRoot);
    g_hcsTreeRoot = NULL;
}
static bool CreateHcsToTree(void)
{
    uint32_t length;
    const unsigned char *hcsBlob = NULL;
    HdfGetBuildInConfigData(&hcsBlob, &length);
    if (!HcsCheckBlobFormat((const char *)hcsBlob, length)) {
        return false;
    }
    if (!HcsDecompile((const char *)hcsBlob, HBC_HEADER_LENGTH, &g_hcsTreeRoot)) {
        return false;
    }
    return true;
}
