#include <common.h>
#include <spl.h>
#include "common.h"
#include <dm.h>
#include <remoteproc.h>
#include <linux/soc/ti/ti_sci_protocol.h>
#include <fdt_support.h>
#include <asm/arch/sys_proto.h>
#include <asm/hardware.h>
#include <asm/io.h>
#ifdef CONFIG_K3_EARLY_CONS
#endif
#ifdef CONFIG_SYS_K3_SPL_ATF
#endif
#if defined(CONFIG_OF_LIBFDT)
#endif
#ifndef CONFIG_SYSRESET
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
#ifdef CONFIG_ARM64
#endif
#ifdef CONFIG_CPU_V7R
#endif
