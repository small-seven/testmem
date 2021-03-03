#include <common.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/arch/clock.h>
#include <div64.h>
#include <asm/arch/sys_proto.h>
#ifdef CONFIG_MX53
#endif
#ifdef	CONFIG_MX53
#endif
#define AHB_CLK_ROOT    133333333
#define SZ_DEC_1M       1000000
#define PLL_PD_MAX      16      /* Actual pd+1 */
#define PLL_MFI_MAX     15
#define PLL_MFI_MIN     5
#define ARM_DIV_MAX     8
#define IPG_DIV_MAX     4
#define AHB_DIV_MAX     8
#define EMI_DIV_MAX     8
#define NFC_DIV_MAX     8
#define MX5_CBCMR	0x00015154
#define MX5_CBCDR	0x02888945
#define PLL_FREQ_MAX(ref_clk)  (4 * (ref_clk) * PLL_MFI_MAX)
#define PLL_FREQ_MIN(ref_clk) \
#define MAX_DDR_CLK     420000000
#define NFC_CLK_MAX     34000000
#ifdef CONFIG_SYS_I2C_MXC
#if defined(CONFIG_MX51)
#elif defined(CONFIG_MX53)
#endif
#endif
#if defined(CONFIG_MX51)
#elif defined(CONFIG_MX53)
#endif
#ifdef CONFIG_MX51
#endif
#if defined(CONFIG_MX51)
#elif defined(CONFIG_MX53)
#endif
#ifdef CONFIG_MX51
#endif
#define calc_div(tgt_clk, src_clk, limit) ({		\
#define CHANGE_PLL_SETTINGS(pll, pd, fi, fn, fd) \
#ifdef CONFIG_MX53
#endif
#ifdef CONFIG_FSL_IIM
#endif
#ifdef CONFIG_MX53
#else
#endif
#ifdef CONFIG_MX53
#endif
#ifndef CONFIG_SPL_BUILD
#ifdef	CONFIG_MX53
#endif
#ifdef CONFIG_MXC_SPI
#endif
#endif
