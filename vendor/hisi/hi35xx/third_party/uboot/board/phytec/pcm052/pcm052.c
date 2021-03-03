#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux-vf610.h>
#include <asm/arch/ddrmc-vf610.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <env.h>
#include <led.h>
#include <miiphy.h>
#define PCM052_DDRMC_PHY_DQ_TIMING			0x00002213
#define PCM052_DDRMC_PHY_CTRL				0x00290000
#define PCM052_DDRMC_PHY_SLAVE_CTRL			0x00002c00
#define PCM052_DDRMC_PHY_PROC_PAD_ODT			0x00010020
#if defined(CONFIG_TARGET_PCM052)
#elif defined(CONFIG_TARGET_BK4R1)
#else /* Unknown PCM052 variant */
#error DDR characteristics undefined for this target. Please define them.
#endif
#ifdef CONFIG_TARGET_BK4R1
#define MII_KSZ8081_REFERENCE_CLOCK_SELECT	0x1f
#define RMII_50MHz_CLOCK	0x8180
#endif /* CONFIG_TARGET_BK4R1 */
#ifdef CONFIG_TARGET_BK4R1
#else
#endif
