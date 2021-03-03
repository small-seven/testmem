#include <common.h>
#include <div64.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#ifdef CONFIG_FSL_ESDHC_IMX
#include <fsl_esdhc_imx.h>
#endif
#include <netdev.h>
#include <spl.h>
#define CLK_CODE(arm, ahb, sel) (((arm) << 16) + ((ahb) << 8) + (sel))
#define CLK_CODE_ARM(c)		(((c) >> 16) & 0xFF)
#define CLK_CODE_AHB(c)		(((c) >>  8) & 0xFF)
#define CLK_CODE_PATH(c)	((c) & 0xFF)
#define CCM_GET_DIVIDER(x, m, o) (((x) & (m)) >> (o))
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_FEC_MXC
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
#if defined(CONFIG_FEC_MXC)
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#endif
#ifdef CONFIG_FSL_ESDHC_IMX
#if CONFIG_SYS_FSL_ESDHC_ADDR == MMC_SDHC2_BASE_ADDR
#elif CONFIG_SYS_FSL_ESDHC_ADDR == MMC_SDHC3_BASE_ADDR
#else
#endif
#endif
#define RCSR_MEM_CTL_WEIM	0
#define RCSR_MEM_CTL_NAND	1
#define RCSR_MEM_CTL_ATA	2
#define RCSR_MEM_CTL_EXPANSION	3
#define RCSR_MEM_TYPE_NOR	0
#define RCSR_MEM_TYPE_ONENAND	2
#define RCSR_MEM_TYPE_SD	0
#define RCSR_MEM_TYPE_I2C	2
#define RCSR_MEM_TYPE_SPI	3
