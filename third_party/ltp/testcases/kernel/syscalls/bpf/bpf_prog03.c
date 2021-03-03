#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "config.h"
#include "tst_test.h"
#include "tst_capability.h"
#include "lapi/socket.h"
#include "lapi/bpf.h"
#include "bpf_common.h"
#define LOG_SIZE (1024 * 1024)
#define CHECK_BPF_RET(x) ((x) >= 0 || ((x) == -1 && errno != EPERM))
