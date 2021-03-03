#include <common.h>
#include <stdio.h>
#include <linux/io.h>
#include <linux/printk.h>
#include <linux/sizes.h>
#include "../soc-info.h"
#include "ddrmphy-regs.h"
#if 1
#define PRINTF_FORMAT "%2d"
#else
#define PRINTF_FORMAT "%02x"
#endif
#define FS "   "
#define ptr_to_uint(p)	((unsigned int)(unsigned long)(p))
#define UNIPHIER_MAX_NR_DDRMPHY		3
#define REG_DUMP(x)							\
#define DX_REG_DUMP(dx, x)						\
