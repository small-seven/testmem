#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "config.h"
#include "tst_test.h"
#include "tst_capability.h"
#include "lapi/socket.h"
#include "lapi/bpf.h"
#include "bpf_common.h"
#define A64INT (((uint64_t)1) << 60)
