#include "hdf_driver_loader.h"
#include "devsvc_manager_clnt.h"
#include "hcs_tree_if.h"
#include "hdf_device_desc.h"
#include "hdf_device_node.h"
#include "hdf_log.h"
#include "hdf_object_manager.h"
#define HDF_LOG_TAG driver_loader
struct HdfObject *HdfDriverLoaderCreate()
{
    static bool isDriverLoaderInit = false;
    static struct HdfDriverLoader driverLoader;
    if (!isDriverLoaderInit) {
        HdfDriverLoaderConstruct(&driverLoader);
        isDriverLoaderInit = true;
    }
    return (struct HdfObject *)&driverLoader;
}
