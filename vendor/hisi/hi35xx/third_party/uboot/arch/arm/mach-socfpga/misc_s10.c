#include <altera.h>
#include <common.h>
#include <env.h>
#include <errno.h>
#include <fdtdec.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/reset_manager.h>
#include <asm/arch/system_manager.h>
#include <asm/arch/misc.h>
#include <asm/pl310.h>
#include <linux/libfdt.h>
#include <asm/arch/mailbox_s10.h>
#include <dt-bindings/reset/altr,rst-mgr-s10.h>
#ifdef CONFIG_ETH_DESIGNWARE
#else
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
#ifdef CONFIG_ARCH_MISC_INIT
#endif
