#include "init_read_cfg.h"
#include <errno.h>
#include <linux/capability.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "init_jobs.h"
#include "init_perms.h"
#include "init_service_manager.h"
#include "securec.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
#define MAX_SERVICES_CNT_IN_FILE 100
#define MAX_CAPS_CNT_FOR_ONE_SERVICE 100
#define UID_STR_IN_CFG        "uid"
#define GID_STR_IN_CFG        "gid"
#define ONCE_STR_IN_CFG       "once"
#define IMPORTANT_STR_IN_CFG  "importance"
#define BIN_SH_NOT_ALLOWED    "/bin/sh"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
