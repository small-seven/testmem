#include <common.h>
#include <clk.h>
#include <dm.h>
#include <timer.h>
#include <asm/io.h>
#define AT91_PIT_VALUE		0xfffff
#define AT91_PIT_PITEN		BIT(24)		/* Timer Enabled */
