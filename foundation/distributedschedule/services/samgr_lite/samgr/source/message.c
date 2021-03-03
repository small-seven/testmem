#include "message_inner.h"
#include <ohos_errno.h>
#include <log.h>
#include "memory_adapter.h"
#include "queue_adapter.h"
#include "securec.h"
#include "task_manager.h"
#undef LOG_TAG
#undef LOG_DOMAIN
#define LOG_TAG "Samgr"
#define LOG_DOMAIN 0xD001800
#define DONT_WAIT 0
#define WAIT_FOREVER (-1)
int32 SAMGR_FreeMsg(Exchange *exchange)
{
    if (!FreeReference(exchange)) {
        return EC_SUCCESS;
    }

    if (exchange->request.len > 0) {
        SAMGR_Free(exchange->request.data);
        exchange->request.data = NULL;
    }

    if (exchange->response.len > 0) {
        SAMGR_Free(exchange->response.data);
        exchange->response.data = NULL;
    }
    return EC_SUCCESS;
}
static BOOL FreeReference(Exchange *exchange)
{
    if (exchange == NULL) {
        return FALSE;
    }

    BOOL needFree = TRUE;
    /* 1. check the shared reference */
    MUTEX_GlobalLock();
    if (exchange->sharedRef != NULL) {
        if (*(exchange->sharedRef) > 0) {
            (*(exchange->sharedRef))--;
        }

        if (*(exchange->sharedRef) > 0) {
            needFree = FALSE;
        }
    }
    MUTEX_GlobalUnlock();

    if (needFree) {
        SAMGR_Free(exchange->sharedRef);
        exchange->sharedRef = NULL;
    }
    return needFree;
}