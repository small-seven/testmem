#include <common.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#define	PLL_FREQ_KHZ	480000
#define	PLL_FREQ_COEF	18
#define	XTAL_FREQ_KHZ	24000
#define	PLL_FREQ_MHZ	(PLL_FREQ_KHZ / 1000)
#define	XTAL_FREQ_MHZ	(XTAL_FREQ_KHZ / 1000)
#if defined(CONFIG_MX23)
#define MXC_SSPCLK_MAX MXC_SSPCLK0
#elif defined(CONFIG_MX28)
#define MXC_SSPCLK_MAX MXC_SSPCLK3
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#endif
#if defined(CONFIG_MX23)
#elif defined(CONFIG_MX28)
#endif
#ifdef CONFIG_MX28
#endif
