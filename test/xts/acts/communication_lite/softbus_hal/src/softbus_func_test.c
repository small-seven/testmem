#include "hctest.h"
#include "discovery_service.h"
#include "session.h"
#include "securec.h"
#include <unistd.h>
#include <stdlib.h>
#define PUB_SUCCESS 1
#define PUB_FAIL (-1)
#define TESTCASE_COUNT 23
#define ERROR_SESSION_ID (-1)
#define SESSION_NAME_LEN 64
#define SOFTBUS_TEST_SUCCESS 0
#define SOFTBUS_TEST_FAIL (-1)
#define ONE_SECOND 1
#define DEF_TIMEOUT 6
#define DEF_DEVTYPE "L0"
#define DEF_DEVID "sb_test_default_devid"
#define DEF_PUB_ID 33113322
#define DEF_PUB_MODULE_NAME "sb_pub_module_name"
#define DEF_PUB_CAPABILITY "ddmpCapability"
#define DEF_PUB_CAPABILITYDATA_LEN 2
#define DEVID_MAX_LEN 96
