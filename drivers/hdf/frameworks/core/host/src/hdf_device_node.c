#include "hdf_device_node.h"
#include "devhost_service.h"
#include "devmgr_service_clnt.h"
#include "devsvc_manager_clnt.h"
#include "hdf_base.h"
#include "hdf_device_object.h"
#include "hdf_device_token.h"
#include "hdf_log.h"
#include "hdf_object_manager.h"
#include "hdf_observer_record.h"
#include "osal_mem.h"
#include "power_state_token.h"
#define HDF_LOG_TAG device_node
void HdfDeviceNodeFreeInstance(struct HdfDeviceNode *devNode)
{
    HdfObjectManagerFreeObject((struct HdfObject *) devNode);
}
