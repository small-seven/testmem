#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <errno.h>
#include <netdev.h>
#include <asm/io.h>
#include <linux/compiler.h>
#include <dm/platform_data/serial_pl01x.h>
#include "pcie.h"
#include <asm/armv8/mmu.h>
#ifdef PHYS_SDRAM_2
#endif
#ifdef CONFIG_SMC91111
#endif
#ifdef CONFIG_SMC911X
#endif
