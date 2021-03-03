#include <time.h>
#include <errno.h>
#include "syscall.h"
#define IS32BIT(x) !((x)+0x80000000ULL>>32)
#ifdef SYS_clock_settime64
#else
#endif
