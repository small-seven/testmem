#include <common.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#ifdef CONFIG_FSL_USDHC
#if CONFIG_SYS_FSL_ESDHC_ADDR == USDHC2_BASE_ADDR
#elif CONFIG_SYS_FSL_ESDHC_ADDR == USDHC3_BASE_ADDR
#elif CONFIG_SYS_FSL_ESDHC_ADDR == USDHC4_BASE_ADDR
#else
#endif
#else
#if CONFIG_SYS_FSL_ESDHC_ADDR == MMC_SDHC2_BASE_ADDR
#elif CONFIG_SYS_FSL_ESDHC_ADDR == MMC_SDHC3_BASE_ADDR
#elif CONFIG_SYS_FSL_ESDHC_ADDR == MMC_SDHC4_BASE_ADDR
#else
#endif
#endif
#endif
