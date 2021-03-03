#define _GNU_SOURCE
#include <poll.h>
#include <signal.h>
#include <errno.h>
#include "syscall.h"
#include <unsupported_api.h>
#define IS32BIT(x) !((x)+0x80000000ULL>>32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU+((0ULL+(x))>>63))
#ifdef SYS_ppoll_time64
#endif
