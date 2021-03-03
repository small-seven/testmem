#include <sys/select.h>
#include <signal.h>
#include <stdint.h>
#include <errno.h>
#include "syscall.h"
#define IS32BIT(x) !((x)+0x80000000ULL>>32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU+((0ULL+(x))>>63))
#ifdef SYS_pselect6_time64
#endif
#ifdef SYS_select
#else
#endif
