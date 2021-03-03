#include <common.h>
#include <div64.h>
#include <time.h>
#ifdef CONFIG_ARCH_CINTEGRATOR
#define DIV_CLOCK_INIT	1
#define TIMER_LOAD_VAL	0xFFFFFFFFL
#else
#define DIV_CLOCK_INIT	256
#define TIMER_LOAD_VAL	0x0000FFFFL
#endif
#define READ_TIMER (*(volatile ulong *)(CONFIG_SYS_TIMERBASE+4))
#ifdef CONFIG_ARCH_CINTEGRATOR
#else
#endif
