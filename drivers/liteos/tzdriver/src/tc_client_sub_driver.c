#include "tc_client_sub_driver.h"
#include "agent.h"
#include "gp_ops.h"
#include "mailbox_mempool.h"
#ifdef SECURITY_AUTH_ENHANCE
#include "security_auth_enhance.h"
#endif
#include "smc.h"
#include "tc_client_driver.h"
#include "tc_ns_log.h"
#include "tzdriver_compat.h"
#ifdef SECURITY_AUTH_ENHANCE
typedef struct {
    TcNsDevFile *devFile;
    TcNsClientContext *context;
    TcNsSession *session;
} GetSecureInfoParams;
#endif
#define MAX_REF_COUNT 255
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
