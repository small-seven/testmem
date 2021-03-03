#define _GNU_SOURCE
#include <sys/socket.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include "syscall.h"
#define IS32BIT(x) !((x)+0x80000000ULL>>32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU+((0ULL+(x))>>63))
#if LONG_MAX > INT_MAX
#endif
#ifdef SYS_recvmmsg_time64
#else
#endif
