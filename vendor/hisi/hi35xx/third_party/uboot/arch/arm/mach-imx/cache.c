#include <common.h>
#include <cpu_func.h>
#include <asm/armv7.h>
#include <asm/pl310.h>
#include <asm/io.h>
#include <asm/mach-imx/sys_proto.h>
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#if defined(CONFIG_SYS_ARM_CACHE_WRITETHROUGH)
#else
#endif
#else
#endif
#ifndef CONFIG_SYS_L2CACHE_OFF
#ifdef CONFIG_SYS_L2_PL310
#define IOMUXC_GPR11_L2CACHE_AS_OCRAM 0x00000002
#endif /* !CONFIG_SYS_L2_PL310 */
#endif /* !CONFIG_SYS_L2CACHE_OFF */
