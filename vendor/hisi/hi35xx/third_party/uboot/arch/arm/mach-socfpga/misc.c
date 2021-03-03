#include <common.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <errno.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <altera.h>
#include <miiphy.h>
#include <netdev.h>
#include <watchdog.h>
#include <asm/arch/misc.h>
#include <asm/arch/reset_manager.h>
#include <asm/arch/scan_manager.h>
#include <asm/arch/system_manager.h>
#include <asm/arch/nic301.h>
#include <asm/arch/scu.h>
#include <asm/pl310.h>
#ifdef CONFIG_SYS_L2_PL310
#endif
#if !CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#ifdef CONFIG_SYS_L2_PL310
#endif
#if defined(CONFIG_SYS_CONSOLE_IS_IN_ENV) && \
#endif
#ifdef CONFIG_FPGA
#endif
#ifdef CONFIG_HW_WATCHDOG
#else
#endif
#ifndef CONFIG_SPL_BUILD
#endif
