#include <common.h>
#include <asm/arch/dram.h>
#ifdef CONFIG_DRAM_TIMINGS_VENDOR_MAGIC
#else
#	include "dram_timings_sun4i.h"
#endif
