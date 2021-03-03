#include "service_impl.h"
#include <string.h>
#include "memory_adapter.h"
#include "thread_adapter.h"
#include "time_adapter.h"
#include "feature_impl.h"
#include "service_registry.h"
ServiceImpl *SAMGR_CreateServiceImpl(Service *service, uint8 step)
{
    ServiceImpl *impl = (ServiceImpl *)SAMGR_Malloc(sizeof(ServiceImpl));
    if (impl == NULL) {
        return NULL;
    }
    impl->service = service;
    impl->defaultApi = NULL;
    impl->taskPool = NULL;
    impl->features = VECTOR_Make((VECTOR_Key)GetFeatureName, (VECTOR_Compare)strcmp);
    impl->serviceId = INVALID_INDEX;
    impl->inited = SVC_INIT;
    impl->ops.abnormal = 0;
    impl->ops.messages = 0;
    impl->ops.step = step;
    impl->ops.timestamp = (uint32)SAMGR_GetProcessTime();
    return impl;
}
