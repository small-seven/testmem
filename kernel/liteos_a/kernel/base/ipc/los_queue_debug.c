#include "los_queue_debug_pri.h"
#include "los_hw_pri.h"
#include "los_ipcdebug_pri.h"
#ifdef LOSCFG_SHELL
#include "shcmd.h"
#endif /* LOSCFG_SHELL */
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
#ifdef LOSCFG_DEBUG_QUEUE
typedef struct {
    TSK_ENTRY_FUNC creater; /* The task entry who created this queue */
    UINT64  lastAccessTime; /* The last access time */
} QueueDebugCB;
#ifdef LOSCFG_SHELL_CMD_DEBUG
#endif /* LOSCFG_SHELL */
#endif /* LOSCFG_DEBUG_QUEUE */
#ifdef __cplusplus
#if __cplusplus
#endif
#endif /* __cplusplus */
