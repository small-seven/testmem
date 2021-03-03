#include <common.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clock.h>
#include <asm/arch/hardware.h>
#include <asm/io.h>
#define PRCM_MOD_EN		0x2
#define OSC_SRC0		0
#define OSC_SRC1		1
#define L3_OSC_SRC		OSC_SRC0
#define OSC_0_FREQ		20
#define DCO_HS2_MIN		500
#define DCO_HS2_MAX		1000
#define DCO_HS1_MIN		1000
#define DCO_HS1_MAX		2000
#define SELFREQDCO_HS2		0x00000801
#define SELFREQDCO_HS1		0x00001001
#define MPU_N			0x1
#define MPU_M			0x3C
#define MPU_M2			1
#define MPU_CLKCTRL		0x1
#define L3_N			19
#define L3_M			880
#define L3_M2			4
#define L3_CLKCTRL		0x801
#define DDR_N			19
#define DDR_M			666
#define DDR_M2			2
#define DDR_CLKCTRL		0x801
#define ADPLLJ_CLKCTRL_HS2	0x00000801 /* HS2 mode, TINT2 = 1 */
#define ADPLLJ_CLKCTRL_HS1	0x00001001 /* HS1 mode, TINT2 = 1 */
#define ADPLLJ_CLKCTRL_CLKDCOLDOEN	(1 << 29)
#define ADPLLJ_CLKCTRL_IDLE		(1 << 23)
#define ADPLLJ_CLKCTRL_CLKOUTEN		(1 << 20)
#define ADPLLJ_CLKCTRL_CLKOUTLDOEN	(1 << 19)
#define ADPLLJ_CLKCTRL_CLKDCOLDOPWDNZ	(1 << 17)
#define ADPLLJ_CLKCTRL_LPMODE		(1 << 12)
#define ADPLLJ_CLKCTRL_DRIFTGUARDIAN	(1 << 11)
#define ADPLLJ_CLKCTRL_REGM4XEN		(1 << 10)
#define ADPLLJ_CLKCTRL_TINITZ		(1 << 0)
#define ADPLLJ_CLKCTRL_CLKDCO		(ADPLLJ_CLKCTRL_CLKDCOLDOEN | \
#define ADPLLJ_STATUS_PHASELOCK		(1 << 10)
#define ADPLLJ_STATUS_FREQLOCK		(1 << 9)
#define ADPLLJ_STATUS_PHSFRQLOCK	(ADPLLJ_STATUS_PHASELOCK | \
#define ADPLLJ_STATUS_BYPASSACK		(1 << 8)
#define ADPLLJ_STATUS_BYPASS		(1 << 0)
#define ADPLLJ_STATUS_BYPASSANDACK	(ADPLLJ_STATUS_BYPASSACK | \
#define ADPLLJ_TENABLE_ENB		(1 << 0)
#define ADPLLJ_TENABLEDIV_ENB		(1 << 0)
#define ADPLLJ_M2NDIV_M2SHIFT		16
#define MPU_PLL_BASE			(PLL_SUBSYS_BASE + 0x048)
#define L3_PLL_BASE			(PLL_SUBSYS_BASE + 0x110)
#define DDR_PLL_BASE			(PLL_SUBSYS_BASE + 0x290)
#define OSC_SRC_CTRL			(PLL_SUBSYS_BASE + 0x2C0)
#define ENET_CLKCTRL_CMPL		0x30000
#define SATA_PLL_BASE			(CTRL_BASE + 0x0720)
#define SEL_IN_FREQ		(0x1 << 31)
#define DIGCLRZ			(0x1 << 30)
#define ENDIGLDO		(0x1 << 4)
#define APLL_CP_CURR		(0x1 << 3)
#define ENBGSC_REF		(0x1 << 2)
#define ENPLLLDO		(0x1 << 1)
#define ENPLL			(0x1 << 0)
#define SATA_PLLCFG0_1 (SEL_IN_FREQ | ENBGSC_REF)
#define SATA_PLLCFG0_2 (SEL_IN_FREQ | ENDIGLDO | ENBGSC_REF)
#define SATA_PLLCFG0_3 (SEL_IN_FREQ | ENDIGLDO | ENBGSC_REF | ENPLLLDO)
#define SATA_PLLCFG0_4 (SEL_IN_FREQ | DIGCLRZ | ENDIGLDO | ENBGSC_REF | \
#define PLL_LOCK		(0x1 << 0)
#define ENSATAMODE		(0x1 << 31)
#define PLLREFSEL		(0x1 << 30)
#define MDIVINT			(0x4b << 18)
#define EN_CLKAUX		(0x1 << 5)
#define EN_CLK125M		(0x1 << 4)
#define EN_CLK100M		(0x1 << 3)
#define EN_CLK50M		(0x1 << 2)
#define SATA_PLLCFG1 (ENSATAMODE |	\
#define DIGLDO_EN_CAPLESSMODE	(0x1 << 22)
#define PLLDO_EN_LDO_STABLE	(0x1 << 11)
#define PLLDO_EN_BUF_CUR	(0x1 << 7)
#define PLLDO_EN_LP		(0x1 << 6)
#define PLLDO_CTRL_TRIM_1_4V	(0x10 << 1)
#define SATA_PLLCFG3 (DIGLDO_EN_CAPLESSMODE |	\
