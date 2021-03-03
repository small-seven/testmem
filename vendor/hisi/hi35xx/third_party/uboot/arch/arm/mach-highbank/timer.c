#include <common.h>
#include <asm/io.h>
#include <asm/arch-armv7/systimer.h>
#undef SYSTIMER_BASE
#define SYSTIMER_BASE		0xFFF34000	/* Timer 0 and 1 base	*/
