#include <time.h>
#include <limits.h>
#include "pthread_impl.h"
#define IS32BIT(x) !((x)+0x80000000ULL>>32)
#ifdef SYS_timer_settime64
#endif
