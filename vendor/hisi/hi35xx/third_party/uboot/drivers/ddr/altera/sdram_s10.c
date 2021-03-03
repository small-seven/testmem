#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <div64.h>
#include <fdtdec.h>
#include <ram.h>
#include <reset.h>
#include "sdram_s10.h"
#include <wait_bit.h>
#include <asm/arch/firewall_s10.h>
#include <asm/arch/system_manager.h>
#include <asm/arch/reset_manager.h>
#include <asm/io.h>
#include <linux/sizes.h>
#define DDR_CONFIG(A, B, C, R)	(((A) << 24) | ((B) << 16) | ((C) << 8) | (R))
#define PGTABLE_OFF	0x4000
