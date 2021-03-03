#include <common.h>
#include <time.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/at91_tc.h>
#include <asm/arch/clk.h>
#define TIMER_LOAD_VAL (CONFIG_SYS_HZ_CLOCK/CONFIG_SYS_HZ)
