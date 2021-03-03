#include "samgr_lite_inner.h"
#include <string.h>
#include <securec.h>
#include <ohos_errno.h>
#include <log.h>
#include "memory_adapter.h"
#include "time_adapter.h"
#include "thread_adapter.h"
#include "service_impl.h"
#include "feature_impl.h"
#include "service_registry.h"
#undef LOG_TAG
#undef LOG_DOMAIN
#define LOG_TAG "Samgr"
#define LOG_DOMAIN 0xD001800
#define TO_NEXT_STATUS(status) (BootStatus)((uint8)(status) | 0x1)
