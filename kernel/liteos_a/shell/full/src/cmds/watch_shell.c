#include "shcmd.h"
#include "shmsg.h"
#include "unistd.h"
#include "stdio.h"
#include "time.h"
#include "los_event.h"
#include "securec.h"
#define  timeval64      timeval
#define  gettimeofday64 gettimeofday
#define  ctime64        ctime
#ifdef LOSCFG_SHELL_CMD_DEBUG
typedef struct {
    BOOL title; /* whether to hide the timestamps */
    UINT32 count; /* the total number of command executions */
    UINT32 interval; /* running cycle of the command */
    EVENT_CB_S watchEvent; /* event handle of the watch structure */
    CHAR cmdbuf[CMD_MAX_LEN]; /* the command to watch */
} WatchCB;
#define WATCH_COUNT_MAX 0xFFFFFF
#define WATCH_INTETVAL_MAX 0xFFFFFF
#endif
