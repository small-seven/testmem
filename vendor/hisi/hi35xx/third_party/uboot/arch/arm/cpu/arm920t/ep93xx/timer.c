#include <common.h>
#include <time.h>
#include <linux/types.h>
#include <asm/arch/ep93xx.h>
#include <asm/io.h>
#include <div64.h>
#define TIMER_CLKSEL	(1 << 3)
#define TIMER_ENABLE	(1 << 7)
#define TIMER_FREQ			508469		/* ticks / second */
#define TIMER_MAX_VAL			0xFFFFFFFF
