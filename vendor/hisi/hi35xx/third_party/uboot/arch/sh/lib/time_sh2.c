#include <common.h>
#include <time.h>
#include <asm/io.h>
#include <asm/processor.h>
#define CMT_CMCSR_INIT	0x0001	/* PCLK/32 */
#define CMT_CMCSR_CALIB 0x0000
#define CMT_MAX_COUNTER (0xFFFFFFFF)
#define CMT_TIMER_RESET (0xFFFF)
