#include <common.h>
#include <cpu_func.h>
#include <linux/bitops.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/psci.h>
#include <linux/sizes.h>
#include <asm/processor.h>
#include <asm/psci.h>
#include <asm/secure.h>
#include "../debug.h"
#include "../soc-info.h"
#include "arm-mpcore.h"
#include "cache-uniphier.h"
#define UNIPHIER_SMPCTRL_ROM_RSV2	0x59801208
