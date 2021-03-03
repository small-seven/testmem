#include <common.h>
#include <cpu_func.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/mach-imx/boot_mode.h>
#if !(defined(CONFIG_MX51) || defined(CONFIG_MX53))
#error "CPU_TYPE not defined"
#endif
#ifdef CONFIG_MX51
#else
#endif
#if defined(CONFIG_MX51)
#else
#endif
#ifdef CONFIG_REVISION_TAG
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#endif
#if defined(CONFIG_FEC_MXC)
#endif
#ifdef CONFIG_MX53
#endif
