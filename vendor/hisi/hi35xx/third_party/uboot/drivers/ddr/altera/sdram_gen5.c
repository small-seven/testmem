#include <common.h>
#include <dm.h>
#include <errno.h>
#include <div64.h>
#include <ram.h>
#include <reset.h>
#include <watchdog.h>
#include <asm/arch/fpga_manager.h>
#include <asm/arch/reset_manager.h>
#include <asm/arch/sdram.h>
#include <asm/arch/system_manager.h>
#include <asm/io.h>
#include "sequencer.h"
#ifdef CONFIG_SPL_BUILD
#define MEMSIZE_4G	(4ULL * 1024ULL * 1024ULL * 1024ULL)
#endif /* CONFIG_SPL_BUILD */
