#include "tee_client_api.h"
#include <errno.h>     /* for errno */
#include <fcntl.h>
#include <securec.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h> /* for ioctl */
#include <sys/mman.h>  /* for mmap */
#include <sys/types.h> /* for open close */
#include <unistd.h>
#include "tc_ns_client.h"
#include "tee_auth_common.h"
#include "tee_ca_daemon.h"
#include "tee_client_app_load.h"
#include "tee_client_id.h"
#include "tee_client_inner.h"
#include "tee_list.h"
#include "tee_log.h"
#include "teec_compat.h"
#define TEE_ERROR_CA_AUTH_FAIL 0xFFFFCFE5
#define AGENT_BUFF_SIZE           0x1000
#define CA_AUTH_RETRY_TIMES       30
#define H_OFFSET                  32
#define SHIFT    3
#define MASK     0x7
#define BYTE_BIT 8
#ifdef SECURITY_AUTH_ENHANCE
typedef struct {
    uint8_t uuid[UUID_LEN];
    uint32_t sessionId;
    uint8_t teecToken[TOKEN_SAVE_LEN];
    int fd;
    tee_list_t tokenNode;
    uint32_t opsCnt;
} TC_NS_Token;
#endif
TEEC_Session *FindAndRemoveSession(const TEEC_Session *session, TEEC_ContextHal *context)
{
    TEEC_Session *sSession = NULL;

    if (session == NULL || context == NULL) {
        tloge("find and remove session: context or session is NULL!\n");
        return NULL;
    }

    int lockRet = pthread_mutex_lock(&context->sessionLock);
    if (lockRet != 0) {
        tloge("get session lock failed.\n");
        return NULL;
    }
    sSession = FindBnSession(session, context);
    if (sSession != NULL) {
        TeeListDelete(&sSession->head);
    }
    (void)pthread_mutex_unlock(&context->sessionLock);
    return sSession;
}
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
#ifdef SECURITY_AUTH_ENHANCE
#endif
