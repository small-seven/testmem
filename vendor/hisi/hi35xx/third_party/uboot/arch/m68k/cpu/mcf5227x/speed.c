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
#ifdef CONFIG_CF_SBF
#endif
#ifdef CONFIG_SYS_I2C_FSL
#endif
