#include "distributed_schedule_service.h"
#include <pthread.h>
#include "distributed_service_interface.h"
#include "dmslite_log.h"
#include "ohos_init.h"
#include "samgr_lite.h"
#define STACK_SIZE 0x800
#define QUEUE_SIZE 20
#define EMPTY_SERVICE_NAME ""
