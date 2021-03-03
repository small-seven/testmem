#include <common.h>
#include <asm/io.h>
#include <env.h>
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
#include <asm/arch/sdram.h>
#include <asm/arch/system_manager.h>
#include <asm/arch/nic301.h>
#include <asm/arch/scu.h>
#include <asm/pl310.h>
#include <dt-bindings/reset/altr,rst-mgr.h>
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
#ifdef CONFIG_ARCH_MISC_INIT
#endif
#ifndef CONFIG_SPL_BUILD
#endif
