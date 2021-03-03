#include <common.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clock.h>
#define TIMER_CLOCK		(V_SCLK / (2 << CONFIG_SYS_PTV))
#define TIMER_OVERFLOW_VAL	0xffffffff
#define TIMER_LOAD_VAL		0
