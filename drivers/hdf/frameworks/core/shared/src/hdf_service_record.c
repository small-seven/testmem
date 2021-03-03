#include "hdf_service_record.h"
#include "osal_mem.h"
void DevSvcRecordFreeInstance(struct DevSvcRecord *inst)
{
    if (inst != NULL) {
        OsalMemFree(inst);
    }
}
