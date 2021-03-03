#include <common.h>
#include <asm/processor.h>
#include <asm/immap.h>
#include <asm/io.h>
#define CLOCK_LPD_MIN		(1 << 0)	/* Divider (decoded) */
#define CLOCK_LPD_MAX		(1 << 15)	/* Divider (decoded) */
#define CLOCK_PLL_FVCO_MAX	540000000
#define CLOCK_PLL_FVCO_MIN	300000000
#define CLOCK_PLL_FSYS_MAX	266666666
#define CLOCK_PLL_FSYS_MIN	100000000
#define MHZ			1000000
#ifdef CONFIG_MCF5445x
#endif
#ifdef CONFIG_MCF5441x
#ifdef CONFIG_LOW_MCFCLK
#endif
#endif
#ifdef CONFIG_MCF5445x
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_M54455EVB
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_M54455EVB
#endif
#ifdef CONFIG_M54451EVB
#ifdef CONFIG_CF_SBF
#else
#endif
#endif
#ifdef CONFIG_PCI
#endif
#ifdef CONFIG_SYS_I2C_FSL
#endif
#endif
#ifdef CONFIG_MCF5441x
#endif
#ifdef CONFIG_MCF5445x
#endif
#ifdef CONFIG_SYS_FSL_I2C
#endif
