#include <common.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/timer_defs.h>
#include <div64.h>
#define TIMER_LOAD_VAL	0xffffffff
#define TIM_CLK_DIV	16
#ifdef CONFIG_HW_WATCHDOG
#endif
