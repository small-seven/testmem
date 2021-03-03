#include <common.h>
#include <cpu_func.h>
#include <vsprintf.h>
#include <watchdog.h>
#include <command.h>
#include <mpc8xx.h>
#include <netdev.h>
#include <asm/cache.h>
#include <asm/cpm_8xx.h>
#include <linux/compiler.h>
#include <asm/io.h>
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#include <fdt_support.h>
#endif
#ifdef CONFIG_SYS_RESET_ADDRESS
#else
#endif
#define PLPRCR_val(a) ((pll & PLPRCR_ ## a ## _MSK) >> PLPRCR_ ## a ## _SHIFT)
#if defined(CONFIG_MPC8XX_FEC)
#endif
