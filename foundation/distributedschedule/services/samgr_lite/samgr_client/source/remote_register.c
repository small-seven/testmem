#include "remote_register.h"
#include <ohos_errno.h>
#include <ohos_init.h>
#include <liteipc_adapter.h>
#include <log.h>
#include "policy_define.h"
#include "samgr_lite.h"
#include "memory_adapter.h"
#include "thread_adapter.h"
#include "iproxy_client.h"
#include "default_client.h"
#undef LOG_TAG
#undef LOG_DOMAIN
#define LOG_TAG "Samgr"
#define LOG_DOMAIN 0xD001800
#define RETRY_INTERVAL 2
#define MAX_RETRY_TIMES 10
#define MAX_POLICY_NUM 8
