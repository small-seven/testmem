#include "init_cmds.h"
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <unistd.h>
#include "init_service_manager.h"
#include "securec.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
#define MODE_LEN 4   // for chmod mode, format 0xxx
#define DEFAULT_DIR_MODE 0755  // mkdir, default mode
#define SPACES_CNT_IN_CMD_MAX 10   // mount, max number of spaces in cmdline
#define SPACES_CNT_IN_CMD_MIN 2    // mount, min number of spaces in cmdline
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
