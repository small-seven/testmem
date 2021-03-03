#include "hdf_driver_installer.h"
#include "devhost_service.h"
#include "hdf_base.h"
#include "hdf_log.h"
#include "hdf_object_manager.h"
#define HDF_LOG_TAG driver_installer
struct HdfObject *DriverInstallerCreate(void)
{
    static bool isDriverInstInit = false;
    static struct DriverInstaller driverInstaller;
    if (!isDriverInstInit) {
        DriverInstallerConstruct(&driverInstaller);
        isDriverInstInit = true;
    }
    return (struct HdfObject *)&driverInstaller;
}
