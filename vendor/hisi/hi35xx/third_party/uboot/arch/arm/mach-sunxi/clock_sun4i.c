#include <common.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/arch/sys_proto.h>
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_MACH_SUN7I
#endif
#ifdef CONFIG_SUNXI_AHCI
#endif
#endif
#ifdef CONFIG_SPL_BUILD
#define PLL1_CFG(N, K, M, P)	( 1 << CCM_PLL1_CFG_ENABLE_SHIFT | \
#endif
