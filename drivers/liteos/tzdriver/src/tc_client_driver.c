#include "tc_client_driver.h"
#include "agent.h"
#include "gp_ops.h"
#include "mailbox_mempool.h"
#include "mem.h"
#include "smc.h"
#include "tc_client_sub_driver.h"
#include "tc_ns_log.h"
#include "teek_client_constants.h"
#include "teek_client_type.h"
#include "tz_spi_notify.h"
#include "tzdebug.h"
#include "tzdriver_compat.h"
#define TEEC_PARAM_TYPES(param0_type, param1_type, param2_type, param3_type) \
#define TEEC_PARAM_TYPE_GET(paramTypes, index) \
#define TEECD_CERT_INDEX 0
typedef struct {
    TcNsDevFile *devFile;
    char *fileBuffer;
    unsigned int fileSize;
} LoadImageParams;
#define LIBTEEC_CODE_PAGE_SIZE 8
#define DEFAULT_TEXT_OFF 0
#define LIBTEEC_NAME_MAX_LEN 50
#define LIBTEEC_SO "/vendor/lib/libteec_vendor.so"
#ifdef SECURITY_AUTH_ENHANCE
#endif
#define MAX_BUF_LEN 4096
#ifdef CONFIG_ASAN_DEBUG
#endif
#ifdef TC_ASYNC_NOTIFY_SUPPORT
#endif
#ifdef SECURITY_AUTH_ENHANCE
#else
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef DEF_ENG
#endif
#ifdef DEF_ENG
#endif
