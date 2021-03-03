#include "tee_client_app_load.h"
#include <errno.h>     /* for errno */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h> /* for ioctl */
#include <sys/mman.h>  /* for mmap */
#include <sys/stat.h>
#include <sys/types.h> /* for open close */
#include <unistd.h>
#include "secfile_load_agent.h"
#include "securec.h"
#include "tc_ns_client.h"
#include "tee_client_inner.h"
#include "tee_log.h"
#include "teec_compat.h"
#define MAX_PATH_LEN 256
