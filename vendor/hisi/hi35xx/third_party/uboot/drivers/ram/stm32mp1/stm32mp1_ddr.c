#include <common.h>
#include <clk.h>
#include <ram.h>
#include <reset.h>
#include <timer.h>
#include <asm/io.h>
#include <asm/arch/ddr.h>
#include <linux/iopoll.h>
#include "stm32mp1_ddr.h"
#include "stm32mp1_ddr_regs.h"
#define RCC_DDRITFCR		0xD8
#define RCC_DDRITFCR_DDRCAPBRST		(BIT(14))
#define RCC_DDRITFCR_DDRCAXIRST		(BIT(15))
#define RCC_DDRITFCR_DDRCORERST		(BIT(16))
#define RCC_DDRITFCR_DPHYAPBRST		(BIT(17))
#define RCC_DDRITFCR_DPHYRST		(BIT(18))
#define RCC_DDRITFCR_DPHYCTLRST		(BIT(19))
#define INVALID_OFFSET	0xFF
#define DDRCTL_REG(x, y) \
#define DDRPHY_REG(x, y) \
#define DDR_REG_DYN(x) \
#define DDRPHY_REG_DYN(x) \
#define DDRCTL_REG_REG_SIZE	25	/* st,ctl-reg */
#define DDRCTL_REG_TIMING_SIZE	12	/* st,ctl-timing */
#define DDRCTL_REG_MAP_SIZE	9	/* st,ctl-map */
#define DDRCTL_REG_PERF_SIZE	17	/* st,ctl-perf */
#define DDRPHY_REG_REG_SIZE	11	/* st,phy-reg */
#define	DDRPHY_REG_TIMING_SIZE	10	/* st,phy-timing */
#define	DDRPHY_REG_CAL_SIZE	12	/* st,phy-cal */
#define DDRCTL_REG_REG(x)	DDRCTL_REG(x, stm32mp1_ddrctrl_reg)
#define DDRCTL_REG_TIMING(x)	DDRCTL_REG(x, stm32mp1_ddrctrl_timing)
#define DDRCTL_REG_MAP(x)	DDRCTL_REG(x, stm32mp1_ddrctrl_map)
#define DDRCTL_REG_PERF(x)	DDRCTL_REG(x, stm32mp1_ddrctrl_perf)
#define DDRPHY_REG_REG(x)	DDRPHY_REG(x, stm32mp1_ddrphy_reg)
#define DDRPHY_REG_TIMING(x)	DDRPHY_REG(x, stm32mp1_ddrphy_timing)
#define DDRPHY_REG_CAL(x)	DDRPHY_REG(x, stm32mp1_ddrphy_cal)
#ifdef CONFIG_STM32MP1_DDR_INTERACTIVE
#define DDR_REG_DYN_SIZE	ARRAY_SIZE(ddr_dyn)
#define DDRPHY_REG_DYN_SIZE	ARRAY_SIZE(ddrphy_dyn)
#endif
#ifdef CONFIG_STM32MP1_DDR_INTERACTIVE
#endif
#define DDRPHY_REG_CAL(x)	DDRPHY_REG(x, stm32mp1_ddrphy_cal)
#ifdef CONFIG_STM32MP1_DDR_INTERACTIVE
#endif
#ifdef CONFIG_STM32MP1_DDR_INTERACTIVE
#endif
#define INTERACTIVE(step)\
