#include <common.h>
#include <config.h>
#include <serial.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <linux/compiler.h>
#include "mxs_init.h"
#ifdef CONFIG_SPL_SERIAL_SUPPORT
#endif
#if defined(CONFIG_MX23)
#define	MUX_CONFIG_BOOTMODE_PAD	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_NOPULL)
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#define GLOBAL_BOOT_MODE_ADDR 0x00019BF0
#endif
#ifdef CONFIG_SPL_SERIAL_SUPPORT
#endif
#ifndef CONFIG_SPL_FRAMEWORK
#endif
