#include "hos_types.h"
#include <securec.h>
#include "hctest.h"
#include "los_config.h"
#include "kal.h"
#include "cmsis_os2.h"
#include "los_task_pri.h"
#define MILLISEC_NUM_10 10
#define MILLISEC_NUM_1000 1000
#define TICK_NUM_10 10
#define TICK_NUM_20 20
#define TICK_NUM_30 30
#define TICK_NUM_40 40
#define TICK_NUM_1000 1000
#define TESTCOUNT_NUM_1 1
#define TESTCOUNT_NUM_2 2
#define TESTCOUNT_NUM_3 3
#define TESTCOUNT_NUM_4 4
#define TESTCOUNT_NUM_5 5
#define TEST_TASK_STACK_SIZE      0x600
#define TEST_TASK_PRIORITY_LOW          osPriorityBelowNormal       // tskIDLE_PRIORITY + 10
#define TEST_TASK_PRIORITY_NORMAL       osPriorityNormal            // tskIDLE_PRIORITY + 11
#define TEST_TASK_PRIORITY_HIGH         osPriorityAboveNormal       // tskIDLE_PRIORITY + 12
#define PRIORITY_TRANSFORM_NUM 39
