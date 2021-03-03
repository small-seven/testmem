#include "hiview_hievent.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "los_memory.h"
#include "los_task_pri.h"
#include "los_process_pri.h"
#include "los_task_pri.h"
#include "los_mux.h"
#include "los_mp.h"
#include "los_typedef.h"
#include "los_typedef.h"

#include "hievent_driver.h"

#define INT_TYPE_MAX_LEN    21

#define MAX_PATH_LEN        256
#define MAX_STR_LEN         (10 * 1024)

/* 64K is max length of /dev/hwlog_exception */
#define EVENT_INFO_BUF_LEN         (64 * 1024)
#define EVENT_INFO_PACK_BUF_LEN    (2 * 1024)

#define HWLOG_ERR  PRINT_ERR
#define HWLOG_INFO PRINT_INFO

#define BUF_POINTER_FORWARD                     \
    do {                                        \
        if (tmplen < len) {                     \
            tmp += tmplen;                      \
            len -= tmplen;                      \
        } else {                                \
static struct HiviewHieventPayload *HiviewHieventPayloadCreate(void)
{
    struct HiviewHieventPayload *payload = NULL;

    payload = LOS_MemAlloc((VOID *)OS_SYS_MEM_ADDR,
                           sizeof(struct HiviewHieventPayload));
    if (!payload) {
        return NULL;
    }

    payload->key = NULL;
    payload->value = NULL;
    payload->next = NULL;

    return payload;
}
static void HiviewHieventPayloadDestroy(struct HiviewHieventPayload *p)
{
    if (!p) {
        return;
    }

    if (p->value) {
        LOS_MemFree((VOID *)OS_SYS_MEM_ADDR, p->value);
    }

    LOS_MemFree((VOID *)OS_SYS_MEM_ADDR, p->key);
    LOS_MemFree((VOID *)OS_SYS_MEM_ADDR, p);
}
struct HiviewHievent *HiviewHieventCreate(unsigned int eventid)
{
    struct HiviewHievent *event = NULL;

    /* combined event obj struct */
    event = LOS_MemAlloc((VOID *)OS_SYS_MEM_ADDR, sizeof(*event));
    if (!event) {
        return NULL;
    }

    (VOID)memset_s(event, sizeof(*event), 0, sizeof(*event));
    event->eventid = eventid;
    HWLOG_INFO("%s : %u\n", __func__, eventid);

    return (void *)event;
}
#define IDAP_LOGTYPE_CMD 1
void HiviewHieventDestroy(struct HiviewHievent *event)
{
    int i;
    struct HiviewHieventPayload *p = NULL;

    if (!event) {
        return;
    }
    p = event->head;
    while (p) {
        struct HiviewHieventPayload *del = p;

        p = p->next;
        HiviewHieventPayloadDestroy(del);
    }
    event->head = NULL;
    for (i = 0; i < MAX_PATH_NUMBER; i++) {
        LOS_MemFree((VOID *)OS_SYS_MEM_ADDR, event->filePath[i]);
        event->filePath[i] = NULL;
    }
    LOS_MemFree((VOID *)OS_SYS_MEM_ADDR, event);
}
