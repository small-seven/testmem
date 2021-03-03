#include <common.h>
#include <errno.h>
#include <stdio_dev.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <asm/global_data.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <asm/armv7.h>
#include <asm/psci.h>
#ifdef CONFIG_ARMV7_SECURE_RESERVE_SIZE
#else /* !CONFIG_ARMV7_SECURE_RESERVE_SIZE */
#endif
#ifdef CONFIG_ARMV7_NONSEC
#endif
#ifndef CONFIG_ARMV7_SECURE_BASE
#endif
