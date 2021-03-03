#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/sendfile.h>
#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/abisize.h"
#ifndef OFF_T
#define OFF_T off_t
#endif /* Not def: OFF_T */
#define ONE_GB (INT64_C(1) << 30)
#ifdef TST_ABI32
#endif
