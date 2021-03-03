#include <sys/timerfd.h>
#include <errno.h>
#include "syscall.h"
#define IS32BIT(x) !((x)+0x80000000ULL>>32)
#ifdef SYS_timerfd_settime64
#endif
#ifdef SYS_timerfd_gettime64
#endif
