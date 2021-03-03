#include "devmgr_service_clnt.h"
#include "hdf_base.h"
#include "hdf_device.h"
#include "hdf_log.h"
#include "hdf_object_manager.h"
#define HDF_LOG_TAG devmgr_service_clnt
void DevmgrServiceClntFreeInstance(struct DevmgrServiceClnt *inst)
{
    if ((inst != NULL) && (inst->devMgrSvcIf != NULL)) {
        HdfObjectManagerFreeObject((struct HdfObject *)inst->devMgrSvcIf);
        inst->devMgrSvcIf = NULL;
    }
}
