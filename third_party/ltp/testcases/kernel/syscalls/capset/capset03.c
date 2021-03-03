#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include <linux/capability.h>
#define CAP1 (1 << CAP_KILL)
#define CAP2 (CAP1 | 1 << CAP_NET_RAW)
