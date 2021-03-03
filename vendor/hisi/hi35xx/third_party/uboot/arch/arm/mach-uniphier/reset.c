#include <common.h>
#include <linux/io.h>
#include <asm/secure.h>
#include "sc-regs.h"
#ifdef CONFIG_ARMV7_PSCI
#define __SECURE	__secure
#else
#define __SECURE
#endif
