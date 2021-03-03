#include "gp_ops.h"
#include <securec.h>
#include "agent.h"
#include "mailbox_mempool.h"
#include "mem.h"
#include "smc.h"
#include "tc_client_sub_driver.h"
#include "tc_ns_log.h"
#include "teek_client_constants.h"
#include "tzdriver_compat.h"
#ifdef SECURITY_AUTH_ENHANCE
#include "security_auth_enhance.h"
#define AES_LOGIN_MAXLEN   (((MAX_PUBKEY_LEN) > (MAX_PACKAGE_NAME_LEN)) ? \
#endif
typedef struct {
    TcNsDevFile *devFile;
    TcNsClientContext *clientContext;
    TcNsSession *session;
    TcNsTempBuf *localTempBuffer;
    unsigned int tmpBufSize;
} TcCallParams;
typedef struct {
    TcNsDevFile *devFile;
    TcNsClientContext *clientContext;
    TcNsSession *session;
    TcNsOperation *operation;
    TcNsTempBuf *localTempBuffer;
    unsigned int tmpBufSize;
    unsigned int *transParamTypeToTee;
    unsigned int TransParamTypeSize;
} AllocParams;
typedef struct {
    TcNsDevFile *devFile;
    TcNsClientContext *clientContext;
    TcNsOperation *operation;
    TcNsTempBuf *localTempBuffer;
    unsigned int tmpBufSize;
    bool isComplete;
} UpdateParams;
#define MAX_SHARED_SIZE 0x100000      /* 1 MiB */
#define TEEC_PARAM_TYPES(param0_type, param1_type, param2_type, param3_type) \
#define TEEC_PARAM_TYPE_GET(paramTypes, index) \
#define ROUND_UP(N, S) (((N)+(S)-1)&(~((S)-1)))
#define INPUT_DIR 0
#define OUTPUT_DIR 1
#define BOTH_DIR 2
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#else
#endif
#ifdef SECURITY_AUTH_ENHANCE
#ifdef TC_ASYNC_NOTIFY_SUPPORT
#endif
#define TEE_TZMP \
#define INVALID_TZMP_UID   0xffffffff
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef CONFIG_TEE_SMP
#endif
#ifdef TC_ASYNC_NOTIFY_SUPPORT
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef TC_ASYNC_NOTIFY_SUPPORT
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
