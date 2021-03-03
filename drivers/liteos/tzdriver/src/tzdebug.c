#include "tzdebug.h"
#include <securec.h>
#include <stdarg.h>
#include "cmdmonitor.h"
#include "mailbox_mempool.h"
#include "smc.h"
#include "tc_client_sub_driver.h"
#include "tc_ns_log.h"
#include "teek_client_api.h"
#include "teek_client_constants.h"
#include "teek_ns_client.h"
#include "tzdriver_compat.h"
typedef void (*TzdebugOptFunc)(const char *param);

struct OptOps {
    char *name;
    TzdebugOptFunc func;
};
#define TC_NS_CLIENT_TZDEBUG "/dev/tzdebug"
