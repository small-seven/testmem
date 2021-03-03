#include "queue_adapter.h"
#include <cmsis_os.h>
#include <ohos_types.h>
#include <ohos_errno.h>
MQueueId QUEUE_Create(const char *name, int size, int count)
{
    osMessageQueueAttr_t queueAttr = {name, 0, NULL, 0, NULL, 0};
    return (MQueueId)osMessageQueueNew(count, size, &queueAttr);
}
int QUEUE_Destroy(MQueueId queueId)
{
    osStatus_t evt = osMessageQueueDelete(queueId);
    if (evt != osOK) {
        return EC_FAILURE;
    }
    return EC_SUCCESS;
}