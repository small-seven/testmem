#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mount.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/loop.h>
#include <stdint.h>
#include <inttypes.h>
#include "lapi/syscalls.h"
#include "test.h"
#include "safe_macros.h"
#ifndef LOOP_CTL_GET_FREE
# define LOOP_CTL_GET_FREE 0x4C82
#endif
#define LOOP_CONTROL_FILE "/dev/loop-control"
#define DEV_FILE "test_dev.img"
#define DEV_SIZE_MB 256u
