#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <dm/root.h>
#include <dt-bindings/clock/stm32h7-clks.h>
#define RCC_CR_HSION			BIT(0)
#define RCC_CR_HSIRDY			BIT(2)
#define RCC_CR_HSEON			BIT(16)
#define RCC_CR_HSERDY			BIT(17)
#define RCC_CR_HSEBYP			BIT(18)
#define RCC_CR_PLL1ON			BIT(24)
#define RCC_CR_PLL1RDY			BIT(25)
#define RCC_CR_HSIDIV_MASK		GENMASK(4, 3)
#define RCC_CR_HSIDIV_SHIFT		3
#define RCC_CFGR_SW_MASK		GENMASK(2, 0)
#define RCC_CFGR_SW_HSI			0
#define RCC_CFGR_SW_CSI			1
#define RCC_CFGR_SW_HSE			2
#define RCC_CFGR_SW_PLL1		3
#define RCC_CFGR_TIMPRE			BIT(15)
#define RCC_PLLCKSELR_PLLSRC_HSI	0
#define RCC_PLLCKSELR_PLLSRC_CSI	1
#define RCC_PLLCKSELR_PLLSRC_HSE	2
#define RCC_PLLCKSELR_PLLSRC_NO_CLK	3
#define RCC_PLLCKSELR_PLLSRC_MASK	GENMASK(1, 0)
#define RCC_PLLCKSELR_DIVM1_SHIFT	4
#define RCC_PLLCKSELR_DIVM1_MASK	GENMASK(9, 4)
#define RCC_PLL1DIVR_DIVN1_MASK		GENMASK(8, 0)
#define RCC_PLL1DIVR_DIVP1_SHIFT	9
#define RCC_PLL1DIVR_DIVP1_MASK		GENMASK(15, 9)
#define RCC_PLL1DIVR_DIVQ1_SHIFT	16
#define RCC_PLL1DIVR_DIVQ1_MASK		GENMASK(22, 16)
#define RCC_PLL1DIVR_DIVR1_SHIFT	24
#define RCC_PLL1DIVR_DIVR1_MASK		GENMASK(30, 24)
#define RCC_PLL1FRACR_FRACN1_SHIFT	3
#define RCC_PLL1FRACR_FRACN1_MASK	GENMASK(15, 3)
#define RCC_PLLCFGR_PLL1RGE_SHIFT	2
#define		PLL1RGE_1_2_MHZ		0
#define		PLL1RGE_2_4_MHZ		1
#define		PLL1RGE_4_8_MHZ		2
#define		PLL1RGE_8_16_MHZ	3
#define RCC_PLLCFGR_DIVP1EN		BIT(16)
#define RCC_PLLCFGR_DIVQ1EN		BIT(17)
#define RCC_PLLCFGR_DIVR1EN		BIT(18)
#define RCC_D1CFGR_HPRE_MASK		GENMASK(3, 0)
#define RCC_D1CFGR_HPRE_DIVIDED		BIT(3)
#define RCC_D1CFGR_HPRE_DIVIDER		GENMASK(2, 0)
#define RCC_D1CFGR_HPRE_DIV2		8
#define RCC_D1CFGR_D1PPRE_SHIFT		4
#define RCC_D1CFGR_D1PPRE_DIVIDED	BIT(6)
#define RCC_D1CFGR_D1PPRE_DIVIDER	GENMASK(5, 4)
#define RCC_D1CFGR_D1CPRE_SHIFT		8
#define RCC_D1CFGR_D1CPRE_DIVIDER	GENMASK(10, 8)
#define RCC_D1CFGR_D1CPRE_DIVIDED	BIT(11)
#define RCC_D2CFGR_D2PPRE1_SHIFT	4
#define RCC_D2CFGR_D2PPRE1_DIVIDED	BIT(6)
#define RCC_D2CFGR_D2PPRE1_DIVIDER	GENMASK(5, 4)
#define RCC_D2CFGR_D2PPRE2_SHIFT	8
#define RCC_D2CFGR_D2PPRE2_DIVIDED	BIT(10)
#define RCC_D2CFGR_D2PPRE2_DIVIDER	GENMASK(9, 8)
#define RCC_D3CFGR_D3PPRE_SHIFT		4
#define RCC_D3CFGR_D3PPRE_DIVIDED	BIT(6)
#define RCC_D3CFGR_D3PPRE_DIVIDER	GENMASK(5, 4)
#define RCC_D1CCIPR_FMCSRC_MASK		GENMASK(1, 0)
#define		FMCSRC_HCLKD1		0
#define		FMCSRC_PLL1_Q_CK	1
#define		FMCSRC_PLL2_R_CK	2
#define		FMCSRC_PER_CK		3
#define RCC_D1CCIPR_QSPISRC_MASK	GENMASK(5, 4)
#define RCC_D1CCIPR_QSPISRC_SHIFT	4
#define		QSPISRC_HCLKD1		0
#define		QSPISRC_PLL1_Q_CK	1
#define		QSPISRC_PLL2_R_CK	2
#define		QSPISRC_PER_CK		3
#define PWR_CR3				0x0c
#define PWR_CR3_SCUEN			BIT(2)
#define PWR_D3CR			0x18
#define PWR_D3CR_VOS_MASK		GENMASK(15, 14)
#define PWR_D3CR_VOS_SHIFT		14
#define		VOS_SCALE_3		1
#define		VOS_SCALE_2		2
#define		VOS_SCALE_1		3
#define PWR_D3CR_VOSREADY		BIT(13)
#define RCC_AHB3ENR	offsetof(struct stm32_rcc_regs, ahb3enr)
#define RCC_AHB1ENR	offsetof(struct stm32_rcc_regs, ahb1enr)
#define RCC_AHB2ENR	offsetof(struct stm32_rcc_regs, ahb2enr)
#define RCC_AHB4ENR	offsetof(struct stm32_rcc_regs, ahb4enr)
#define RCC_APB3ENR	offsetof(struct stm32_rcc_regs, apb3enr)
#define RCC_APB1LENR	offsetof(struct stm32_rcc_regs, apb1lenr)
#define RCC_APB1HENR	offsetof(struct stm32_rcc_regs, apb1henr)
#define RCC_APB2ENR	offsetof(struct stm32_rcc_regs, apb2enr)
#define RCC_APB4ENR	offsetof(struct stm32_rcc_regs, apb4enr)
