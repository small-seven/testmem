#include "tee_agent.h"
#include <dirent.h>
#include <errno.h>     /* for errno */
#include <fcntl.h>
#include <pthread.h>
#include <securec.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h> /* for ioctl */
#include <sys/mman.h>  /* for mmap */
#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/time.h>
#include <sys/types.h> /* for open close */
#include <unistd.h>
#include "secfile_load_agent.h"
#include "tc_ns_client.h"
#include "tcu_authentication.h"
#include "tee_ca_daemon.h"
#include "tee_client_api.h"
#include "tee_log.h"
#include "teec_compat.h"
#define UID_MAX_LEN 16
#define MAXBSIZE 65536
typedef void (*FsWorkFunc)(struct SecStorageType *transControl);
typedef struct {
    FsCmdType cmd;
    FsWorkFunc fn;
} FsWorkTbl;
#define SLEEP_TIME (100 * 1000 * 1000)
