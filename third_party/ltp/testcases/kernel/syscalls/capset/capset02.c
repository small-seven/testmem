#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/prctl.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include <linux/capability.h>
#define CAP1 (1 << CAP_NET_RAW | 1 << CAP_CHOWN  | 1 << CAP_SETPCAP)
#define CAP2 (CAP1 | 1 << CAP_KILL)
